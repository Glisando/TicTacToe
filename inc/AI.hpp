#ifndef AI_HPP
# define AI_HPP

struct AIMove
{
    AIMove();
    AIMove(int score);
    AIMove(AIMove const &ref);
    ~AIMove();

    AIMove &operator=(AIMove const &ref);

    int x;
    int y;
    int score;
    char place;
};

#endif