#include "../inc/Game.hpp"

Game::Game() : _gameOver(false), _multiplayer(false), _Player1('-'), _Player2('-'), _AIPlayer('-'), _turn('X') {}
Game::Game(Game const &ref) { *this = ref; }
Game::~Game() {}

Game &Game::operator=(Game const &ref)
{
    (void)ref;
    return *this;
}

/**
 *  Here I'm start my program and ask user some data
*/ 

void Game::Start(void)
{
    std::regex multi("\\s*(y|n)\\s*");
    std::smatch result;
    
    std::cout << std::endl << "Character X always start the game!" << std::endl << std::endl;
    do
    {
        std::cout << "Multiplayer? (y / n): ";
        std::getline(std::cin, _input);
    }
    while (!std::regex_match(_input, result, multi));

    _multiplayer = result[1] == "y" ? true : false;
    (_multiplayer == true) ? multiplayerGame() : GameWithAI();
}

/**
 * Getting step from user
*/ 

char Game::getStep()
{
    char step;
    std::string input;
    std::regex check_field("\\s*([1-9])\\s*");
    std::smatch result;

    do
    {
        std::cout << "Enter the number of field, please [1-9]: ";
        std::getline(std::cin, input);
    }
    while (!std::regex_match(input, result, check_field));
    std::string tmp = result[1];
    step = tmp[0];
    return (step);
}

void Game::chooseCharacter(void)
{
    std::regex player("\\s*(X|O)\\s*");
    std::smatch result;
    
    do
    {
        std::cout << "Would you like to be X or O? (X / O): ";
        std::getline(std::cin, _input);
    }
    while (!std::regex_match(_input, result, player));

    if (_multiplayer)
    {
        _Player1 = result[1] == "X" ? 'X' : 'O';
        _Player2 = _Player1 == 'X' ? 'O' : 'X';
    }
    else
    {
        _Player1 = result[1] == "X" ? 'X' : 'O';
        _AIPlayer = _Player1 == 'X' ? 'O' : 'X';        
    }
}
