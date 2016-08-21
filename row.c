/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 22:57:01 by mhorn             #+#    #+#             */
/*   Updated: 2016/08/20 22:57:03 by mhorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

/*
** check_rows goes through the columns in a row and checks
** to see if a number can only be in one spot.
** i loops through each row. j loops through each square and checks if 
** number k is a possible solution.
*/

int check_rows(Square ***sudoku)
{
	int i;
	int j;
	int k;
	int sum[9];
	int place[9];

	i = 0;
	j = 0;
	k = 0;
	while (i < 9)
	{
		while(j < 9)
		{
			sum[j] = 0;
			j++;
		}
		j = 0;
		while(j < 9)
		{
			if (sudoku[i][j] != 0)
			{
				continue;
			}
			while(k < 9)
			{
				if (sudoku[i][j] ->possible[k] == 0)
				{
					sum[k]++;
					place[k] = j;
				}
			}
			j++;
		}
		k = 0;
		while (k < 9)
		{
			if (sum[k] == 1)
			{
				sudoku[i][j][place[k]].number = (k + 1);
				sudoku[i][place[k]] ->solvable = 0;
				UNSOLVED--;
				update_sudoku(sudoku, i, place[k]);
				update_boxes(sudoku, i, place[k]);
				return (1);
			}
			k++;
		}
		i++;
	}
	return (0);
}
