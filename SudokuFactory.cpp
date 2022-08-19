#include "SudokuFactory.h"
#include <iostream>

using namespace std;

SudokuFactory::SudokuFactory()
{
    reproduction = new SudokuOffspring();
    fitness = new SudokuFitness();
}

SudokuFactory::~SudokuFactory()
{

}

shared_ptr<Puzzle> SudokuFactory::createPuzzle() //creates first input from command line input
{
    shared_ptr<Puzzle> sudoku(new Sudoku());
    cout << "Please enter the 81 numbers representing the sudoku puzzle" << endl;
    cin >> *sudoku;
    sudoku->fitness = 1000; // auto set high fitness so it's guaranteed to change
    return sudoku;
}

shared_ptr<Puzzle> SudokuFactory::createPuzzle(Puzzle& puzzle)
{
    shared_ptr<Puzzle> offspring = reproduction->makeOffspring(puzzle);
    offspring->fitness = fitness->howFit(*offspring); //have to reevaluate new puzzle for fitness
    return offspring;
}