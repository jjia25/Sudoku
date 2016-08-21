/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 12:26:54 by mhorn             #+#    #+#             */
/*   Updated: 2016/08/20 22:57:30 by mhorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
#define SUDOKU_H
#include <stdlib.h>
#include <stdio.h>

/*
**Unsolved keeps track of how many squares are unsolved
*/

extern int UNSOLVED;
extern int SIZE_ROWS;
extern int SIZE_COLUMNS;

typedef	struct sudoku
{
	struct Square ***squares;
	struct Box **boxes;
} Sudoku;

/*
** Square is each cell. Square is an array of all the squares in Box
** Box is each 3x3
*/

typedef struct Box
{
	struct 	Square **squares;
	int		numbers;
	int		possible[9];
	int		solvable;
	struct 	Box *next;
} Box;

typedef struct Square
{
	int		number;
	int		possible[9];
	int		solvable;
	Box		*box;
	int		row;
	int		column;
} Square;

int **create_puzzle(int argc, char **argv);
Square ***malloc_sudoku(void);
Sudoku	*set_up_puzzle(int **puzzle);
//void	set_up_puzzle(int **puzzle);
void print_puzzle(int **puzzle);
Sudoku *create_sudoku(Square ***puzzle, Box **boxes);
int	update_sudoku(Square ***sudoku, int row, int column);
int check_puzzle(Square ***sudoku, Box **boxes);
// int check_puzzle(Square ***sudoku);
int solve_square(Square *square);
Box **create_boxes();
int	update_boxes(Square ***sudoku, int row, int column);
int check_rows(Square ***sudoku);
int box_singles(Square ***sudoku, Box **boxes);

#endif
