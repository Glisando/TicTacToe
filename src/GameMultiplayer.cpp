#include "../inc/Game.hpp"

/**
 * This is a game loop for playing in multiplayer mode
*/

void Game::multiplayerGame(void)
{
    Board board;
    chooseCharacter();
    while (!_gameOver)
    {
        std::cout << std::endl << "Player " << _turn << "'s turn" << std::endl;
        board.printDesk();
        do{}
        while (!board.setDesk(getStep(), _turn)); // I will ask the data from user until he don't give me valid
        board.printDesk();
        _gameOver = board.checkEndOfGame(_turn);
        _turn = _turn == _Player1 ? _Player2 : _Player1; // condition for player change
    }
}