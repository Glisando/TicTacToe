#include "../inc/Game.hpp"

/**
 * This is the main function for playing in single mode.
*/ 

void Game::GameWithAI()
{
    Board board;
    chooseCharacter();
    while (1) // game loop
    {
        if (_turn == _Player1)
        {
            board.printDesk();
            std::cout << std::endl << "It's your turn" << std::endl;
            do{}
            while (!board.setDesk(getStep(), _turn));
        }
        else
        {
            AIMove move;
            move = getBestMove(board, _turn);
            board.setDesk(move, _turn);
        }
        if (board.checkEndOfGame(_turn))
            break ;
        _turn = _turn == _Player1 ? _AIPlayer : _Player1; // condition for player change
    }
}

/**
 * An algo which I use here calls "Minimax Algorithm".
 * This is a recursive algorithm for getting the best move.
 * He models a separate game for every possible move.
 * Gives score for them and return the coordinates of move with the highest score.
*/

AIMove Game::getBestMove(Board &board, char Player)
{
    char ch = board.checkEndOfGame(_Player1, _AIPlayer);
    // exit conditions
    if (ch == _AIPlayer) 
        return AIMove(10);
    else if (ch == _Player1)
        return AIMove(-10);
    else if (ch == 'N') // case if nobody won
        return AIMove(0);

    std::vector<AIMove> moves; // vector of all moves

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (board.getValue(x, y) < 'O')
            {
                AIMove move;
                move.x = x;
                move.y = y;
                board.setDesk(move, Player);
                if (Player == _AIPlayer)
                    move.score = getBestMove(board, _Player1).score;
                else
                    move.score = getBestMove(board, _AIPlayer).score;

                moves.push_back(move);
                board.setDesk(move, move.place);
            }
        }
    }
    int Bmove = chooseBestMove(moves, Player);
    return (moves[Bmove]);
}

/**
 * This function return the best move for current player
*/ 

int Game::chooseBestMove(std::vector<AIMove> moves, char player)
{
    int Bmove = 0;
    int Bscore = 0;
    
    if (player == _Player1)
    {
        Bscore = 99999999;
        for (size_t i = 0; i < moves.size(); i++)
        {
            if (moves[i].score < Bscore)
            {
                Bmove = i;
                Bscore = moves[i].score;
            }
        }
    }
    else
    {
        Bscore = -99999999;
        for (size_t i = 0; i < moves.size(); i++)
        {
            if (moves[i].score > Bscore)
            {
                Bmove = i;
                Bscore = moves[i].score;
            }
        }
    }
    return (Bmove);
}