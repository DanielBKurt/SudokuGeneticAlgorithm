#include "SudokuPopulation.h"

using namespace std;

SudokuPopulation::SudokuPopulation(int popSize, int generations)
{
    this->popSize = popSize;
    this->generations = generations;
    this->currentGen = 1; //constructor creates first gen by default, therefore start at 1
    this->factory = make_unique<SudokuFactory>();
    this->originalPuzzle = factory->createPuzzle(); //creates starting puzzle
    cout << "Inputted puzzle: " << endl;
    cout << *originalPuzzle << endl;
    //create first generation based off of input puzzle
    for (int i = 0; i < popSize; i++)
    {
        shared_ptr<Puzzle> newSudoku = factory->createPuzzle(*originalPuzzle); //create popSize number of offspring, first generation
        gen.push(newSudoku); //add each offspring to gen queue
    }
}
SudokuPopulation::SudokuPopulation(int popSize, int generations, shared_ptr<Puzzle> original)
{
    this->popSize = popSize;
    this->generations = generations;
    this->currentGen = 1; //constructor creates first gen by default, therefore start at 1
    this->factory = make_unique<SudokuFactory>();
    this->originalPuzzle = original;
    cout << "Inputted puzzle: " << endl;
    cout << *originalPuzzle << endl;
    //create first generation based off of input puzzle
    for (int i = 0; i < popSize; i++)
    {
        shared_ptr<Puzzle> newSudoku = factory->createPuzzle(*original); //create popSize number of offspring, first generation
        gen.push(newSudoku); //add each offspring to gen queue
    }
}

SudokuPopulation::~SudokuPopulation()
{

}

int SudokuPopulation::bestFitness()
{
    return this->bestFitPuzzle->getFitness();
}

shared_ptr<Puzzle> SudokuPopulation::bestIndividual()
{
    return this->bestFitPuzzle;
}

shared_ptr<Puzzle> SudokuPopulation::getOriginalPuzzle()
{
    return this->originalPuzzle;
}

void SudokuPopulation::cull()
{
    while (gen.size() > 0) //while not empty
    {
        shared_ptr<Puzzle> current = gen.front();
        gen.pop();
        if (best.size() < (popSize / 10)) //priority queue is not full, still less than 10% of original population
        {
            best.push(current);
            //checking if bestFitPuzzle is null doesn't work for some reason so the below if sees if this is first puzzle
            //if (first puzzle added) || (better than bestFitPuzzle)
            if ((currentGen == 1 && best.size() == 1) || bestFitPuzzle->getFitness() > current->getFitness())
            {
                bestFitPuzzle = current;
            }
        }
        else if (best.top()->getFitness() > current->getFitness()) //is full, is current better fit than top of best?
        {
            if (bestFitPuzzle->getFitness() > current->getFitness()) //same logic as above
            {
                bestFitPuzzle = current;
            }
            best.pop(); //remove worst fit
            best.push(current); //replace with current
        }
    }
}

void SudokuPopulation::newGeneration()
{
    while (best.size() > 0)
    {
        //cant easily iterate over priority queue, therefor clear it and refill it in cull method
        shared_ptr<Puzzle> top = best.top();
        best.pop();
        gen.push(top); //push puzzle to gen
        for (int i = 0; i < 9; i++) //cull leaves 10%, take current and make 9 of each for 100%
        {
            shared_ptr<Puzzle> newPuzzle = factory->createPuzzle(*top); //similar to constructor, create offspring of puzzle
            gen.push(newPuzzle);
        }
    }
    currentGen++;
}

int SudokuPopulation::getCurrentGen()
{
    return this->currentGen;
}