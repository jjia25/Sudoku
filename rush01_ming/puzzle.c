#include "sudoku.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		**malloc_array(void)
{
	int		**puzzle;
	int 	i;

	i = 0;
	puzzle = (int**)malloc(sizeof(int*) * 9);
	while (i < 9)
	{
		puzzle[i] = (int*)malloc(sizeof(int) * 9);
		i++;
	}
	return (puzzle);
}

void	print_array(int **puzzle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		while (j < 9)
		{
			ft_putchar(puzzle[i][j] + '0');
			if (j != 8)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

/*
** Creates an array from the characters passed in from main. Chars are
** converted into ints for ease of use. 
*/

void	create_array(int argc, char **argv)
{
	int i;
	int	j;
	int **puzzle;

	i = 1;
	j = 0;
	puzzle = malloc_array();
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '.')
				puzzle[i - 1][j] = 0;
			else
				puzzle[i - 1][j] = argv[i][j] - '0';
			j++;
		}
		j = 0;
		i++;
	}
	print_array(puzzle);
	sudoku_solver(puzzle, 0, 0);
	print_array(puzzle);
}
