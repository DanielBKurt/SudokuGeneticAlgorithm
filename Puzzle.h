#ifndef PUZZLE_H_
#define PUZZLE_H_

#include <iostream>
#include <memory>
// Interface class for Puzzle
using namespace std;

class Puzzle
{
    public:
        virtual ~Puzzle()
        {
            
        }
  
        //helper methods for istream and ostream
        virtual void fillNumbers(string numbers) = 0;
        virtual void printNumbers() = 0;

        //getter and setter methods for fitness since fitness is protected
        virtual const int getFitness() = 0;
        virtual void setFitness(int fitness) = 0;
  
        friend ostream &operator<<(ostream &output, Puzzle &puzzle);
        friend istream &operator>>(istream &input, Puzzle &puzzle);


    protected:
        int fitness; //universal so that puzzles can be compared easily
};

#endif // PUZZLE_H_