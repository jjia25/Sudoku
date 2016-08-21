/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 22:57:21 by mhorn             #+#    #+#             */
/*   Updated: 2016/08/20 22:57:23 by mhorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int solve_square(Square *square)
{
	int x;
	x = 0;

	while (x < SIZE_ROWS)
	{
		if (square -> possible[x] == 0)
		{
			square ->number = x + 1;
			square -> solvable = 0;
			UNSOLVED--;
		}
	}
	return (0);
}
