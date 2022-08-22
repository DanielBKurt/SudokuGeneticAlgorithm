#include "Population.h"
#include "SudokuPopulation.h"
#include "Puzzle.h"
#include "Sudoku.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <memory>
#include <vector>


using namespace std;

int main()
{
    srand (time(0));
    int pop, gens;
    cout << "Please enter the population size: " << endl;
    cin >> pop;
    cout << "Please enter the maximum number of generations: " << endl;
    cin >> gens;
    shared_ptr<Puzzle> original = nullptr;
    shared_ptr<Puzzle> best = nullptr;
    bool repeat = true;
    vector<int> fitnessByGeneration;
    while (repeat)
    {
        unique_ptr<Population> population;
        if (original == nullptr)
        {
            population = make_unique<SudokuPopulation>(pop, gens);
            original = population->getOriginalPuzzle();
        }
        else
            population = make_unique<SudokuPopulation>(pop, gens, original);
        population->cull(); //SudokuPopulation automatically creates first gen so cull
        while (population->getCurrentGen() < gens && population->bestFitness() != 0) 
        //newGen then cull until max gen reached or solution found
        {
            if (population->getCurrentGen() % (gens / 10 ) == 0) //prints every hundredth generation if max is 1000
            {
                cout << "Current gen: " << population->getCurrentGen() << endl;
                cout << "Current best fitness: " << population->bestFitness() << endl;
                cout << "Current best fit puzzle: " << endl;
                cout << *(population->bestIndividual()) << endl;
            }
            population->newGeneration();
            population->cull();
        }
        cout << "Original puzzle: " << endl;
        cout << *original;
        //prints out ending generation, could be max gens and no solution was found or whatever gen solution is found
        cout << "Number of generations: " << population->getCurrentGen() << endl;
        //prints out fitness of best solution, regardless of if solution is valid or not
        cout << "Best fitness: " << population->bestFitness() << endl;
        //prints out best solution
        cout << *(population->bestIndividual());
        string match;
        bool validString = false;
        while (!validString) //loop till end or rerun is entered
        {
            cout << "Please type 'stop' to stop or 'rerun' to rerun it with the same inputs" << endl;
            cin >> match;
            if (match == "stop")
            {
                validString = true; //string matched to end
                repeat = false; //end while loop
            }
            else if (match == "rerun")
                validString = true; //string matched to rerun, do not end while loop
            else //did not enter end or rerun
                cout << "Sorry, could not match input to end or rerun" << endl;
        }
        if (best == nullptr || population->bestFitness() < best->getFitness())
            best = population->bestIndividual();
        fitnessByGeneration.push_back(population->bestFitness());
        cout << endl << endl << endl;
    }
    if (fitnessByGeneration.size() > 1) //final results of first gen already shown no need to sum just one gen up again
    {
        cout << "Final results:" << endl << endl;
        cout << "Best fitness by run:" << endl;
        for (int i = 0; i < fitnessByGeneration.size(); i++)
        {
            if (i != 0 && i % 20 == 0)
                cout << endl;
            cout << fitnessByGeneration[i] << " ";
        }
        cout << endl << "Best overall fitness: " << best->getFitness() << endl << *best << endl;
        string temp;
        cout << "Please enter anything to end the program (Windows will immediately close the window)" << endl;
        cin >> temp;
    }
    return 0;
}