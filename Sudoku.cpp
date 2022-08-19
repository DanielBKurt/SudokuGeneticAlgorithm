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
    for (int i = 0; i < numbers.size(), count < 81; i++) //loop through string until end of string or all numbers found
    {
        int value;
        switch (numbers[i]) //switch case since numbers[i] is char not int
        {
            case '0':
                value = 0;
                break;
            case '1':
                value = 1;
                break;
            case '2':
                value = 2;
                break;
            case '3':
                value = 3;
                break;
            case '4':
                value = 4;
                break;
            case '5':
                value = 5;
                break;
            case '6':
                value = 6;
                break;
            case '7':
                value = 7;
                break;
            case '8':
                value = 8;
                break;
            case '9':
                value = 9;
                break;
            default: //non number char
                value = -1;
        }
        if (value != -1) //true if numbers[i] is a number and not random char
        {
            //count / 9 gets truncated, 47 % 9 = 5 remainder 2 so it goes in [5][2]
            this->setNumbers[count / 9][count % 9] = value;
            this->potentialSolution[count / 9][count % 9] = value; //fill both arrays
            count++;
        }
    }
}