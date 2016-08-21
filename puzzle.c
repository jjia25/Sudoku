/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 12:32:00 by mhorn             #+#    #+#             */
/*   Updated: 2016/08/20 23:22:42 by mhorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

Sudoku *create_sudoku(Square ***squares, Box **boxes)
{
	Sudoku *sudoku;
	sudoku = malloc(sizeof(Sudoku));

	sudoku ->squares = squares;
	sudoku ->boxes = boxes;

	return (sudoku);
}

/*
** while (i < SIZE_ROWS) loops through rows
** ** malloc space for each row
** while (j < SIZE_COLUMNS) loops through columns
** malloc space for each square
** assign number to sudoku //go back
** assign row and column numbers to each square
*/

/*
** After setting solvable variable, we add the square to 
** squares array in the current box.
** Then set the box value in the square object.
*/

Sudoku	*set_up_puzzle(int **puzzle)
{
	Square	***sudoku;
	Box 	**boxes;
	int		i;
	int		j;
	int		x;
	int		y;
	int		z;
	int current_box = 0;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	z = 0;
	sudoku = malloc_sudoku();
	boxes = create_boxes();
	while (i < SIZE_ROWS)
	{
		while (j < SIZE_COLUMNS)
		{
			sudoku[i][j]->number = puzzle[i][j];
			sudoku[i][j]->row = i;
			sudoku[i][j]->column = j;
			sudoku[i][j] ->solvable = 9;

			boxes[current_box] ->squares[boxes[current_box] ->numbers] 
				= sudoku[i][j];
			sudoku[i][j] ->box = boxes[current_box];
			boxes[current_box] ->numbers++;
			while (x < SIZE_ROWS)
			{
				sudoku[i][j] ->possible[x] = 0;
				x++;
			}
			if (j == 2 || j == 5)
				current_box++;
			j++;
		}

		current_box -= 2;
		if (i == 2 || i == 5)
			current_box = i + 1;
		j = 0;
		i++;
	}
	while (y < SIZE_ROWS)
	{
		while (z < SIZE_COLUMNS)
		{
			if (sudoku[y][z] ->number != 0)
			{
				sudoku[y][z] -> solvable = 0;
				update_sudoku(sudoku, y, z);
				update_boxes(sudoku, y, z);
				UNSOLVED--;
			}
			z++;
		}
		z = 0;
		y++;
	}
	return create_sudoku(sudoku, boxes);
}

/*
** y loops through rows
** z loops through columns
** if the number != 0, the square is not solvable, so we set it to 0
*/

/* 
** Loops through each row in a column.
** Gets the number attribute from the square struct.
** Solavable is the # of numbers we haven't figured out yet in a column.
*/

/*
** update_sudoku checks to see what numbers a square cannot be 
*/

int	update_sudoku(Square ***sudoku, int row, int column)
{
	int x;
	int y;
	int number = sudoku[row][column] -> number;

	x = 0;
	y = 0;
	while (x < SIZE_ROWS) 
	{
		if (sudoku[x][column] ->possible[number -1] == 0)
		{
			sudoku[x][column] ->solvable --;
		}
		sudoku[x][column] ->possible[number - 1] = 1; 
		x++;
	}
	while (y < SIZE_COLUMNS) 
	{
		if (sudoku[row][y] ->possible[number -1] == 0)
		{
			sudoku[row][y] ->solvable --;
		}
		sudoku[row][y] ->possible[number - 1] = 1; 
		y++;
	}
	return (1);
}

int check_puzzle(Square ***sudoku, Box **boxes)
{
	int i;
	int j;
	int x;

	i = 0;
	j = 0;
	x = 0;

	while (i < SIZE_ROWS)
	{
		while (j < SIZE_COLUMNS)
		{
			if (sudoku[i][j] -> solvable == 1)
			{
				solve_square(sudoku[i][j]);
				update_sudoku(sudoku, i, j);
				update_boxes(sudoku, i, j);
				return (1);
			}
			j++;
		}
		i++;
	}
	if (box_singles(sudoku, boxes))
	{
		return (1);
	}
	return check_rows(sudoku);
}

int		**create_puzzle(int argc, char **argv)
{
	int **puzzle;
	int i;
	int j;

	i = 1;
	j = 0;
	puzzle = (int**)malloc(sizeof(int*) * 9);
	while (j < argc)
	{
		puzzle[j] = (int*)malloc(sizeof(int) * 9);
		j++;
	}
	j = 0;
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '.')
				puzzle[i - 1][j] = 0;
			else
			{
				puzzle[i - 1][j] = argv[i][j] - '0';
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (puzzle);
}

void print_puzzle(int **puzzle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	printf("- - - - - - - - - - - - - - - - - - \n");
	while (i < 9)
	{
		while (j < 9)
		{
			printf(" %d ", puzzle[i][j]);
			if (((j + 1) % 3) == 0)
				printf(" | ");
			j++;
		}
		j = 0;
		printf("\n");
		if (((i + 1) % 3) == 0)
		{
			printf("- - - - - - - - - - - - - - - - - - \n");
		}
		i++;
	}
}
