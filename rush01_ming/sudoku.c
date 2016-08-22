#include "sudoku.h"
#include <stdio.h>

/*
** Checks to see if a value is valid in it's current position
** So whether or not the number occurs in it's row, column or box already.
** First checks the value in the row and column of the square then the box.
*/

int	is_valid(int number, int **puzzle, int row, int col)
{
	int i;
	int j;
	int start_column;
	int start_row;

	i = 0;
	while (i < 9)
	{
		if (puzzle[i][col] == number || puzzle[row][i] == number)
			return (0);
		i++;
	}
	start_column = (col / 3) * 3;
	start_row = (row / 3) * 3;
	i = start_row;
	j = start_column;
	while (i <= start_row + 2)
	{
		while (j <= start_column + 2)
		{
			if (puzzle[i][j] == number && i != row && j != col)
					return (0);
			j++;
		}
		j = start_column;
		i++;
	}
	return 1;
}

/*
** Sudoku solver takes a puzzle, row, and column parameters.
** Puzzle gets passed from the create_puzzle function.
** First we check if there is already a value in each square and if it's valid.
** The return values are booleans which tell the function whether or not it
** should recurse.
*/

int	sudoku_solver(int **puzzle, int row, int column)
{
	print_array(puzzle);
	int next_number;

	next_number = 1;
	if (puzzle[row][column] != 0)
	{
		if (column == 8)
			sudoku_solver(puzzle, row + 1, 0);
		else
			sudoku_solver(puzzle, row, column + 1);
	}
	else
	{
    	while (next_number < 10)
    	{
    		if (is_valid(next_number, puzzle, row, column))
    		{
				printf("%d is valid for row, col: %d, %d\n", next_number, row, column);
    			puzzle[row][column] = next_number;
    			if (column >= 8)
    			{
    				if (sudoku_solver(puzzle, row + 1, 0))
					    printf("solving succeeds\n");
    					return (1);
    			}
    			else
    			{
    				if (sudoku_solver(puzzle, row, column + 1))
    					return (1);
    			}
    			puzzle[row][column] = 0;
    		}
    		next_number++;
    	}
	}
	return (0);
}
