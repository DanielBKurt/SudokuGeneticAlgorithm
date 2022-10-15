# Sudoku Genetic Algorithm
This is a genetic algorithm written in C++ which attempts to solve a passed in sudoku puzzle by filling all empty cells (represented by zeroes) with random numbers and then randomly modifying the best fit solutions from the previous generation. It will take the top 10% best fit puzzles from the previous generation, create 9 offspring based on each of the top 10%, which creates a new generation, and then take the top 10% of the new generation. Because it is random, the program will have different results each time it is run, even with the same input string. It can potentially solve a puzzle or it may get "stuck" where the best solutions it can find have very few overlaps but many numbers would need to change to find an actual solution.

I compile it using g++ and the following command: g++ GeneticAlgorithm.cpp Sudoku.cpp SudokuFactory.cpp SudokuFitness.cpp SudokuOffspring.cpp SudokuPopulation.cpp

Sample input strings (more zeroes are harder to solve so the results are less accurate):
409806701001307200030009004500030680090000050026080007300100020004603900908402503
100090005040050090800302004208000603003206400504000709700605001050080030400030002
000000000000030009000890000000000000000030009000890000000000000000030009000890000
