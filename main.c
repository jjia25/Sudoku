/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 12:25:04 by mhorn             #+#    #+#             */
/*   Updated: 2016/08/20 23:21:00 by mhorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int			UNSOLVED = 81;
int 		SIZE_ROWS = 9;
int 		SIZE_COLUMNS = 9;

int		main(int argc, char **argv)
{
	int		**puzzle;
	int		progress;
	Sudoku	*sudoku;

	progress = 0;
	puzzle = create_puzzle(argc, argv);
	sudoku = set_up_puzzle(puzzle);
	print_puzzle(puzzle);
	while (UNSOLVED > 0)
	{
		progress = check_puzzle(sudoku ->squares, sudoku ->boxes);
	 	print_puzzle(puzzle);
	 	if (progress == 0)
	 	 	break;
	 }
	print_puzzle(puzzle);
	return (0);
}
