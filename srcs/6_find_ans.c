#include "ft.h"

void	set(int **ans, int t_row, int t_col)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < t_row)
	{
		if (ans[i][0] == -1)
			ans[i][0] = 1;
		i++;
	}
	while (j < t_col)
	{
		if (ans[0][j] == -1)
			ans[0][j] = 1;
		j++;
	}
	return ;
}

int	minimum(int n1, int n2, int n3)
{
	int	i;

	i = 2147483647;
	if (i > n1)
		i = n1;
	if (i > n2)
		i = n2;
	if (i > n3)
		i = n3;
	return (i);
}

int	set_nbr(int t_row, int t_col, int **ans)
{
	int	i;
	int	j;
	int	max;

	i = 1;
	max = 0;
	while (i < t_row)
	{
		j = 1;
		while (j < t_col)
		{
			if (ans[i][j] == 0)
				j++;
			else
			{
				ans[i][j] = minimum(ans[i][j - 1],
						ans[i - 1][j], ans[i - 1][j - 1]) + 1;
				if (ans[i][j] > max)
					max = ans[i][j];
				j++;
			}
		}
		i++;
	}
	return (max);
}

void	set_ans(int **ans, int t_row, int t_col)
{
	int	max;
	int	*info;

	max = 0;
	set(ans, t_row, t_col);
	max = set_nbr(t_row, t_col, ans);
	info = find_max(ans, t_row, t_col, max);
	ans = change_board(ans, info, max);
}
