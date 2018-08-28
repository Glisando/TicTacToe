#include "Board.hpp"

Board::Board()
{
    char x = '1';

    for (int i = 0; i < 3; i++)
    {
        _desk.push_back(std::vector<char>());
        for (int j = 0; j < 3; j++)
            _desk[i].push_back(x++);
    }
}

Board::Board(Board const &ref)
{
    *this = ref;
}

Board::~Board() {}

Board &Board::operator=(Board const &ref)
{
    this->_desk = ref._desk;
    return *this;
}

std::vector< std::vector<char> > Board::getDesk()
{
    return _desk;
}

bool Board::setDesk(char step, char ch)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) {
            if (_desk[i][j] == step)
            {
                _desk[i][j] = ch;
                return (true);
            }
        }
    }
    std::cout << "This field is busy. Please, try to take another one!" << std::endl;
    return (false);
}

void Board::printDesk()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << _desk[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool Board::checkEndOfGame(char _turn)
{
    bool res = false;

    if (_desk[0][0] == _desk[0][1] && _desk[0][1] == _desk[0][2])
       res = true;
    else if (_desk[1][0] == _desk[1][1] && _desk[1][1] == _desk[1][2])
       res = true;
    else if (_desk[2][0] == _desk[2][1] && _desk[2][1] == _desk[2][2])
       res = true;
    else if (_desk[0][0] == _desk[1][0] && _desk[1][0] == _desk[2][0])
       res = true;
    else if (_desk[0][1] == _desk[1][1] && _desk[1][1] == _desk[2][1])
       res = true;
    else if (_desk[0][2] == _desk[1][2] && _desk[1][2] == _desk[2][2])
       res = true;
    else if (_desk[0][0] == _desk[1][1] && _desk[1][1] == _desk[2][2])
       res = true;
    else if (_desk[0][2] == _desk[1][1] && _desk[1][1] == _desk[3][1])
       res = true;
    else
    {
        for (int i = 0; i < 3; i++)
        {
            if (_desk[i][0] >= 'O' && _desk[i][1] >= 'O' && _desk[i][2] >= 'O')
                continue ;
            else
                return (false);
        }
        std::cout << "Nobody win's" << std::endl;
        return (true);
    }
    if (res)
        std::cout << "Player " << _turn << " win's !!!" << std::endl;
    return (res);
}

