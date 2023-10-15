#include "ft.h"

int	*find_max(int **ans, int t_row, int t_col, int max)
{
	int	*info;

	info = (int *)malloc(sizeof(int) * 6);
	info[0] = 0;
	while (info[0] < t_row)
	{
		info[1] = 0;
		while (info[1] < t_col)
		{
			if (ans[info[0]][info[1]] == max)
			{
				info[2] = info[0];
				info[3] = info[1];
				break ;
			}
			info[1]++;
		}
		if (ans[info[0]][info[1]] == max)
			break ;
		info[0]++;
	}
	info[4] = t_row;
	info[5] = t_col;
	return (info);
}

int	**change_board(int **ans, int *info, int max)
{
	info[0] = 0;
	while (info[0] < info[4])
	{
		info[1] = 0;
		while (info[1] < info[5])
		{
			if ((info[2] - info[0] < max && info[2] - info[0] >= 0)
				&& (info[3] - info[1] < max && info[3] - info[1] >= 0))
				ans[info[0]][info[1]] = 2;
			else if (ans[info[0]][info[1]] == 0)
				ans[info[0]][info[1]] = 1;
			else
				ans[info[0]][info[1]] = 0;
			info[1]++;
		}
		info[0]++;
	}
	free(info);
	return (ans);
}

void	print_ans(int **ans, int t_row, int t_col, char *base)
{
	int		i;
	int		j;
	int		flag;

	flag = 1;
	i = -1;
	while (++i < t_row)
	{
		j = -1;
		while (++j < t_col)
		{
			if ((t_row == 1 || t_col == 1) && ans[i][j] == 0 && flag > 0)
			{
				write(1, &base[2], 1);
				flag--;
			}
			else
				write(1, &base[ans[i][j]], 1);
		}
		write(1, "\n", 1);
	}
	return ;
}

void	free_ans(int **ans, int total_row)
{
	int	i;

	i = -1;
	while (++i < total_row)
		free(ans[i]);
	free(ans);
}
