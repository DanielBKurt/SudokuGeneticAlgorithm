#ifndef SUDOKU_H_
#define SUDOKU_H_

#include "Puzzle.h"
#include <iostream>
#include <memory>

using namespace std;

class Sudoku : public Puzzle 
{
    public:
        Sudoku();
        ~Sudoku();
        void fillNumbers(string numbers);
        void printNumbers();
        void fillPuzzle(string numbers);
        const int getFitness();
        void setFitness(int fitness);
        //not protected like variables in other classes because creating copies of them would significantly slow down program
        int potentialSolution[9][9]; //array that is altered
        int setNumbers[9][9]; //read from command line

};

#endif // SUDOKU_H_