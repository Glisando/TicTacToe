#ifndef BOARD_HPP
# define BOARD_HPP

#include "AI.hpp"
# include <iostream>
# include <vector>

class Board
{
    private:
        std::vector< std::vector<char> > _desk;

    public:
        Board();
        Board(Board const &ref);
        ~Board();

        Board &operator=(Board const &ref);

        std::vector< std::vector<char> > getDesk();
        bool setDesk(char step, char ch);
        void setDesk(AIMove &move, char Player);
        void printDesk();
        char checkEndOfGame(char p1, char p2);
        bool checkEndOfGame(char _turn);
        char getValue(int x, int y);
};

#endif