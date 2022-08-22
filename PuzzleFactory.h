#ifndef PUZZLEFACTORY_H_
#define PUZZLEFACTORY_H_

#include "Puzzle.h"
#include "Reproduction.h"
#include "Fitness.h"
#include <memory>

using namespace std;

class PuzzleFactory
{
    public:
        //shared pointers because regular pointers led to memory issues that caused segmentation fault
        virtual shared_ptr<Puzzle> createPuzzle() = 0;
        virtual shared_ptr<Puzzle> createPuzzle(Puzzle& puzzle) = 0;
        
    protected:
        unique_ptr<Fitness> fitness;
        unique_ptr<Reproduction> reproduction;
};

#endif //PUZZLEFACTORY_H_