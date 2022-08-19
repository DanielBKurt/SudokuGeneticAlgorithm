#include "Population.h"
#include "SudokuPopulation.h"
#include "Puzzle.h"
#include "Sudoku.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <memory>


using namespace std;

int main()
{
    srand (time(0));
    int pop, gens;
    cout << "Please enter the population size: " << endl;
    cin >> pop;
    cout << "Please enter the maximum number of generations: " << endl;
    cin >> gens;
    Population* population = new SudokuPopulation(pop, gens);
    population->cull(); //SudokuPopulation automatically creates first gen so cull
    while (population->getCurrentGen() < gens && population->bestFitness() != 0) 
    //newGen then cull until max gen reached or solution found
    {
        if (population->getCurrentGen() % (gens / 10 ) == 0) //prints every hundredth generation if max is 1000
        {
            cout << "Current gen: " << population->getCurrentGen() << endl;
            cout << "Current best fitness: " << population->bestFitness() << endl;
            cout << *(population->bestIndividual());
        }
        population->newGeneration();
        population->cull();
    }
    cout << "Original puzzle: " << endl;
    cout << *(population->originalPuzzle);
    //prints out ending generation, could be max gens and no solution was found or whatever gen solution is found
    cout << "Number of generations: " << population->getCurrentGen() << endl;
    //prints out fitness of best solution, regardless of if solution is valid or not
    cout << "Best fitness: " << population->bestFitness() << endl;
    //prints out best solution
    cout << *(population->bestIndividual());
    return 0;
}