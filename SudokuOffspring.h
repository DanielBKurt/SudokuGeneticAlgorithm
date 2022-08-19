#ifndef SUDOKUOFFSPRING_H_
#define SUDOKUOFFSPRING_H_

#include "Reproduction.h"
#include "Puzzle.h"
#include "Sudoku.h"

using namespace std;

class SudokuOffspring : public Reproduction
{
    shared_ptr<Puzzle> makeOffspring(Puzzle& puzzle);
};

#endif //SUDOKUOFFSPRING_H_