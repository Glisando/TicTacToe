#include "Game.hpp"

void Game::multiplayerGame(void)
{
    Board board;
    chooseCharacter();
    _turn = 'O';
    while (!_gameOver)
    {
        board.printDesk();
        std::cout << "Player " << _turn << "'s turn" << std::endl;
        do{}
        while (!board.setDesk(getStep(), _turn));
        board.printDesk();        
        _gameOver = board.checkEndOfGame(_turn);
        _turn = _turn == _Player1 ? _Player2 : _Player1;
    }
}