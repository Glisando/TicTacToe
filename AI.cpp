#include "AI.hpp"

AIMove::AIMove() {}
AIMove::AIMove(int sc) : x(0), y(0), score(sc) {}
AIMove::AIMove(AIMove const &ref) { *this = ref; }
AIMove::~AIMove() {}

AIMove &AIMove::operator=(AIMove const &ref)
{
    this->place = ref.place;
    this->score = ref.score;
    this->x = ref.x;
    this->y = ref.y;
    return *this;
}