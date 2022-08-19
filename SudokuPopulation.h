#ifndef SUDOKUPOPULATION_H_
#define SUDOKUPOPULATION_H_

#include "Sudoku.h"
#include "Puzzle.h"
#include "SudokuFactory.h"
#include "Population.h"
#include <queue>

using namespace std;

class SudokuPopulation : public Population
{
    public:
        SudokuPopulation(int popSize, int generations);
        ~SudokuPopulation();
        int bestFitness(); //fitness of best puzzle
        shared_ptr<Puzzle> bestIndividual(); //best puzzle itself
        void cull(); //takes top 10% of gen and puts them into best
        void newGeneration(); //takes all of best, makes 9 offspring of each, places all in gen
        int getCurrentGen(); //returns current gen
};

#endif //SUDOKUPOPULATION_H_