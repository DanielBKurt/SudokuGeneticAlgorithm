#ifndef REPRODUCTION_H_
#define REPRODUCTION_H_


#include "Puzzle.h"
#include <memory>

using namespace std;

class Reproduction
{
    public:
        virtual shared_ptr<Puzzle> makeOffspring(Puzzle& puzzle) = 0;
};

#endif //REPRODUCTION_H_