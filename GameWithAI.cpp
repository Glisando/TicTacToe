#include "Game.hpp"

void Game::GameWithAI()
{
    Board board;
    chooseCharacter();
    _turn = 'O';

    while (1)
    {
        if (_turn == _Player1)
        {
            std::cout << "It's your turn" << std::endl;
            board.printDesk();
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
        _turn = _turn == _Player1 ? _AIPlayer : _Player1;
    }
}

AIMove Game::getBestMove(Board &board, char Player)
{
    char ch = board.checkEndOfGame(_Player1, _AIPlayer);
    if (ch == _AIPlayer)
        return AIMove(10);
    else if (ch == _Player1)
        return AIMove(-10);
    else if (ch == 'N')
        return AIMove(0);

    std::vector<AIMove> moves;

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (board.getValue(x, y) < 'O')
            {
                AIMove move;
                // char pc;
                move.x = x;
                move.y = y;
                board.setDesk(move, Player);
                // pc = move.place;

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