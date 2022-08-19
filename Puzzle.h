#ifndef PUZZLE_H_
#define PUZZLE_H_

#include <iostream>
// Interface class for Puzzle
using namespace std;

class Puzzle
{
    public:
        virtual ~Puzzle()
        {
            
        }
        //bool operators aren't used anymore since I had to change priority queue implementation but I'm leaving them in case implementation changes again
        virtual bool operator>(const Puzzle &puzzle) const = 0;
        virtual bool operator<(const Puzzle &puzzle) const = 0;
  
        //helper methods for istream and ostream
        virtual void fillNumbers(string numbers) = 0;
        virtual void printNumbers() = 0;
  
        friend ostream &operator<<(ostream &output, Puzzle &puzzle);
        friend istream &operator>>(istream &input, Puzzle &puzzle);
        int fitness; //universal so that puzzles can be compared easily
};

#endif // PUZZLE_H_