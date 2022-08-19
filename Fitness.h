#ifndef FITNESS_H_
#define FITNESS_H_

#include "Puzzle.h"

using namespace std;

class Fitness
{
    public:
        virtual int howFit(Puzzle& puzzle) = 0;
};

#endif