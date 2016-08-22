#ifndef SUDOKU_H
#define SUDOKU_H
#include <stdlib.h>

void	ft_putchar(char c);
int		**malloc_array(void);
void	create_array(int argc, char **argv);
void	print_array(int **puzzle);
int		is_valid(int next_number, int **puzzle, int row, int column);
int		sudoku_solver(int **puzzle, int row, int column);
#endif
