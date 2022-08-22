#ifndef POPULATION_H_
#define POPULATION_H_

#include "Puzzle.h"
#include "PuzzleFactory.h"
#include <queue>
#include <memory>

using namespace std;

class Population
{
    protected:
        //implementation in header file because priority queue needs custom comparator
        //priority queue is of pointers, not just objects, so the < and > overload don't work for pointers
        class Compare
        {
            public:
                bool operator() (shared_ptr<Puzzle> A, shared_ptr<Puzzle> B)
                {
                    return (A->getFitness() < B->getFitness());
                }
        };
        shared_ptr<Puzzle> bestFitPuzzle; //best puzzle
        shared_ptr<Puzzle> originalPuzzle; //original, containing zeros, saved to be printed and compared w/ best solution
        unique_ptr<PuzzleFactory> factory;
        int popSize; //passed in by genetic algorithm, population size
        int generations; //passed in by genetic algorithm, max number of generations
        int currentGen; //basically count, makes sure maximum number of generations is not exceeded
        queue<shared_ptr<Puzzle>> gen; //queue of puzzles created by newGeneration()
        priority_queue<shared_ptr<Puzzle>, vector<shared_ptr<Puzzle>>, Compare> best; //best 10%
    public:
        virtual int bestFitness() = 0; //fitness of best puzzle
        virtual shared_ptr<Puzzle> bestIndividual() = 0; //best puzzle itself
        virtual shared_ptr<Puzzle> getOriginalPuzzle() = 0; //passed in puzzle
        virtual int getCurrentGen() = 0;
        virtual void cull() = 0; //takes top 10% of gen and puts them into best
        virtual void newGeneration() = 0; //takes all of best, makes 9 offspring of each, places all in gen
};

#endif