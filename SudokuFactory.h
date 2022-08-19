#ifndef SUDOKUFACTORY_H_
#define SUDOKUFACTORY_H_


#include "PuzzleFactory.h"
#include "Sudoku.h"
#include "SudokuOffspring.h"
#include "SudokuFitness.h"
#include <memory>

using namespace std;

class SudokuFactory : public PuzzleFactory
{
    public:
        SudokuFactory();
        ~SudokuFactory();
        shared_ptr<Puzzle> createPuzzle();
        shared_ptr<Puzzle> createPuzzle(Puzzle& puzzle);
};

#endif //SUDOKUFACTORY_H_