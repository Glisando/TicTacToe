#include "../inc/Game.hpp"

int main(void)
{
    Game game;

    try
    {
        game.Start();
    }
    catch (std::exception &e)
    {
        std::cout << "Something goes wrong :(";
    }
    return (0);
}