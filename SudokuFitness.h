#ifndef SUDOKUFITNESS_H_
#define SUDOKUFITNESS_H_

#include "Puzzle.h"
#include "Sudoku.h"
#include "Fitness.h"

using namespace std;

class SudokuFitness : public Fitness
{
    public:
        SudokuFitness();
        ~SudokuFitness();
        int howFit(Puzzle& puzzle);

        //helper methods for howFit
        int horizontal(Sudoku& sudoku);
        int vertical(Sudoku& sudoku);
        int square(Sudoku& sudoku);
};

#endif //SUDOKUFITNESS_H_