#ifndef GAME_HPP
# define GAME_HPP

# include "Board.hpp"

# include <iostream>
# include <regex>

class Game
{
    private:
        bool        _gameOver;
        bool        _multiplayer;
        std::string _input;
        char        _Player1;
        char        _Player2;
        char        _AIPlayer;
        char        _turn;

    public:
        Game();
        Game(Game const &ref);
        ~Game();

        Game &operator=(Game const &ref);

        void Start(void);
        void multiplayerGame(void);
        void singleGame(void);
        void chooseCharacter(void);
        char getStep();
};

#endif