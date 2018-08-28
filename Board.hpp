#ifndef BOARD_HPP
# define BOARD_HPP

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
        void printDesk();
        bool checkEndOfGame(char _turn);
};

#endif