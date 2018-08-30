#ifndef GAME_HPP
# define GAME_HPP

# include "AI.hpp"
# include "Board.hpp"

# include <iostream>
# include <regex>
# include <string>

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
        void GameWithAI();
        AIMove getBestMove(Board &board, char Player);
        int chooseBestMove(std::vector<AIMove> moves, char player);

};

#endif