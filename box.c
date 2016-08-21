/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 22:56:28 by mhorn             #+#    #+#             */
/*   Updated: 2016/08/20 23:16:29 by mhorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"
#include <stdlib.h>

/*
** Checks if a character possible[j] has only one possible position in the
** row or column. If count == 1 then there is only one possible position.
** Then the square's number is set to j and UNSOLVABLE is decremented
*/
int box_singles(Square ***sudoku, Box **boxes)
{
	int i;
	int j;
	int x;
	int count;
	int temp;

	i = 0;
	j = 0;
	x = 0;
	while (i < 9)
	{
		while(j < 9)
		{
			count = 0;
			while (x  < 9)
			{
				if (boxes[i] ->squares[x] ->possible[j] == 0)
				{
					count++;
					temp = x;
				}
				if (count == 2)
					break;
				x++;
			}
			if (count == 1)
			{
				boxes[i] ->squares[x] -> number = j + 1;
				UNSOLVED --;
				boxes[i] ->squares[temp] ->solvable = 1;
				update_sudoku(sudoku, boxes[i] ->squares[temp] ->row,
				boxes[i] ->squares[temp] ->column);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

/*
** Solvable calculates the number of possible solutions per sqaure.
** A square is solvable once it equals to 1.
*/


Box **create_boxes()
{
	int x;
	int y;
	Box **boxes;
	boxes = malloc(sizeof(Box*) * 9);

	x = 0;
	y = 0;
	while( x < 9)
	{
		boxes[x] = malloc(sizeof(Box));
		boxes[x] ->squares = malloc(sizeof(Square*) * 9);
		boxes[x] ->numbers = 0;
		boxes[x] -> solvable = 9;
		while(y < 9)
		{
			boxes[x] ->possible[y] = 0;
			y++;
		}
		x++;
	}
	return boxes;
}

/*
** When update_boxes comes across a number
** it updates the box to say that none of the squares in that box can be that number.
*/

int	update_boxes(Square ***sudoku, int row, int column)
{
	int x;
	int number = sudoku[row][column] ->number;
	Box *box;
	box = sudoku[row][column] ->box;

	x = 0;
	while(x < 9)
	{
		if (box -> squares[x] ->possible[number - 1] == 0)
		{
			box ->squares[x] ->solvable--;
			box ->squares[x] ->possible[number - 1] = 1;
		}
		x++;
	}
	return (0);
}
