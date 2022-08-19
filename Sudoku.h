#ifndef SUDOKU_H_
#define SUDOKU_H_

#include "Puzzle.h"
#include <iostream>

using namespace std;

class Sudoku : public Puzzle 
{
    public:
        Sudoku();
        ~Sudoku();
        
        //bool operators aren't used anymore since I had to change priority queue implementation 
        // but I'm leaving them in case implementation changes again
        bool operator>(const Puzzle &puzzle) const;
        bool operator<(const Puzzle &puzzle) const;
        void fillNumbers(string numbers);
        void printNumbers();
        int potentialSolution[9][9]; //array that is altered
        int setNumbers[9][9]; //read from command line
        void fillPuzzle(string numbers);

};

#endif // SUDOKU_H_