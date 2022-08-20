#include "Sudoku.h"
#include <iostream>

using namespace std;

Sudoku::Sudoku()
{
    
}

Sudoku::~Sudoku()
{

}

bool Sudoku::operator>(const Puzzle &puzzle) const
{
    return this->fitness > puzzle.fitness;
}

bool Sudoku::operator<(const Puzzle &puzzle) const
{
    return this->fitness < puzzle.fitness;
}


ostream &operator<<(ostream &output, Puzzle &puzzle)
{
    puzzle.printNumbers();
    return output;
}

void Sudoku::printNumbers()
{
    cout << "+-------+-------+-------+" << endl; //top line
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            if (y % 3 == 0) //add dividing line every 3 spaces
                cout << "| "; //include space after column
            cout << this->potentialSolution[x][y] << " "; //include space after each number
        }
        cout << "|" << endl;; //final right line on row
        if ((x == 2 || x == 5 || x == 8)) //add bottom line every 3 rows
            cout << "+-------+-------+-------+" << endl;
    }
}

istream &operator>>(istream &input, Puzzle &puzzle)
{
    string numbers;
    input >> numbers;
    puzzle.fillNumbers(numbers);
    return input;
}

void Sudoku::fillNumbers(string numbers)
{
    int count = 0;
    for (int i = 0; i < numbers.size() && count < 81; i++) //loop through string until end of string or all numbers found
    {
        if (isdigit(numbers.at(i)))
        {
            int value = numbers.at(i) - '0';
            //count / 9 gets truncated, 47 % 9 = 5 remainder 2 so it goes in [5][2]
            this->setNumbers[count / 9][count % 9] = value;
            this->potentialSolution[count / 9][count % 9] = value; //fill both arrays
            count++;
        }
    }
    if (count != 81)
    {
        cout << "Error: invalid string with less than 81 numbers, only contains " << count << " numbers" << endl;
        cout << "String can contain any characters except white spaces" << endl;
        string newNumbers;
        cout << "Please enter a new string with at least 81 numbers" << endl;
        cin >> newNumbers;
        fillNumbers(newNumbers);
    }
}