#ifndef FT_H
# define FT_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_total
{
	int	row;
	int	col;
}	t_total;

typedef struct s_idx
{
	int	i;
	int	argc;
}	t_idx;

void	make_stdin(int *argc, char *argv[]);
int		read_row_base(char *filename, int *total_row, char *base);
int		read_map(char *filename, int *total_row, int *total_col, char *base);
int		**make_map(char *filename, int total_row, int total_col, char *base);
void	set_ans(int **ans, int t_row, int t_col);
void	print_ans(int **ans, int t_row, int t_col, char *base);
void	free_ans(int **ans, int total_row);
int		*find_max(int **ans, int t_row, int t_col, int max);
int		**change_board(int **ans, int *info, int max);
int		base_check(char *str, int *total_row, char *base);
int		map_check(char c, int row, int col, char *base);

#endif
