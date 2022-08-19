#include "SudokuFitness.h"

using namespace std;

SudokuFitness::SudokuFitness()
{

}

SudokuFitness::~SudokuFitness()
{

}

int SudokuFitness::howFit(Puzzle& puzzle)
{
    Sudoku sudoku = dynamic_cast<Sudoku&> (puzzle);
    int count = 0;
    //a number can overlap in its row, column, and square, meaning an otherwise solved puzzle with just one mistake 
    // would have a fitness score of 3
    //this means a few wrong numbers can add up to a high fitness score, even when the puzzle is close to solved
    count += vertical(sudoku);
    count += horizontal(sudoku);
    count += square(sudoku);
    return count;
}

int SudokuFitness::vertical(Sudoku& sudoku)
{
    int count = 0;
    for (int y = 0; y < 9; y++)
    {
        int values[9]; //array of zeros, counts amount of overlaps
        for (int i = 0; i < 9; i++)
            values[i] = 0;
        //3 7s is 3 conflicts, 2 6s is 2 more conflicts, 0 or 1 2s is 0 conflicts from those numbers, total is returned
        for (int x = 0; x < 9; x++)
            values[sudoku.potentialSolution[x][y] - 1] += 1; //maps 1s to values[0], 2s to values[1]...
        for (int x = 0; x < 9; x++)
        {
            if (values[x] > 1)
                count += values[x];
        }
    }
    return count;
}

int SudokuFitness::horizontal(Sudoku& sudoku)
{
    int count = 0;
    for (int x = 0; x < 9; x++)
    {
        int values[9];
        for (int i = 0; i < 9; i++)
            values[i] = 0;
        for (int y = 0; y < 9; y++)
            values[sudoku.potentialSolution[x][y] - 1] += 1;
        for (int y = 0; y < 9; y++)
        {
            if (values[y] > 1)
                count += values[y];
        }
    }
    return count;
}

int SudokuFitness::square(Sudoku& sudoku)
{
    int count = 0;
    int squares[9][2] = {{0,0}, {0,3}, {0,6}, {3,0}, {3,3}, {3,6}, {6,0}, {6,3}, {6,6}}; //hottom left of each square
    for (int w = 0; w < 9; w++)
    {
        int values[9];
        for (int i = 0; i < 9; i++)
            values[i] = 0;
        //go down and right 2 over loops, covers 3x3 square
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
                values[sudoku.potentialSolution[squares[w][0] + x][squares[w][1] + y] - 1] += 1;
        }
        for (int x = 0; x < 9; x++)
        {
            if (values[x] > 1)
                count += values[x];
        }
    }
    return count;
}