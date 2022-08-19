#include "SudokuOffspring.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

shared_ptr<Puzzle> SudokuOffspring::makeOffspring(Puzzle& puzzle)
{
    Sudoku sudokuInput = dynamic_cast<Sudoku&> (puzzle);
    shared_ptr<Sudoku> newSudoku(new Sudoku());
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            newSudoku->potentialSolution[x][y] = sudokuInput.potentialSolution[x][y];
            newSudoku->setNumbers[x][y] = sudokuInput.setNumbers[x][y];
        }
    }
    newSudoku->fitness = sudokuInput.fitness;
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            if (newSudoku->setNumbers[x][y] == 0) //not set number
            {
                int w = rand() % 100;
                if (w < 4 || newSudoku->potentialSolution[x][y] == 0) //4% chance to change
                {
                    newSudoku->potentialSolution[x][y] = rand() % 9 + 1;
                }
            }
        }
    }
    return newSudoku;
}