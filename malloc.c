/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 22:56:45 by mhorn             #+#    #+#             */
/*   Updated: 2016/08/20 22:56:47 by mhorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

Square ***malloc_sudoku(void)
{
	int i;
	int j;
	int k;
	Square ***sudoku;

	i = 0;
	j = 0;
	k = 0;
	sudoku = (Square***)malloc(sizeof(Square**) * 9);
	while (i < SIZE_ROWS)
	{
		sudoku[i] = (Square**)malloc(sizeof(Square*) * 9);
		while (j < SIZE_COLUMNS)
		{
			sudoku[i][j] = (Square*)malloc(sizeof(Square) * 9);
			j++;
		}
		j = 0;
		i++;
	}
	return (sudoku);
}
