#include "ft.h"

int	**make_map2(int **ans, int fd, char *base)
{
	int		row;
	int		col;
	char	buf[1];

	row = 0;
	col = 0;
	while (read(fd, buf, 1))
	{
		if (*buf == base[0])
			ans[row][col] = -1;
		else if (*buf == base[1])
			ans[row][col] = 0;
		else
		{
			row++;
			col = -1;
		}
		col++;
	}
	close(fd);
	return (ans);
}

int	**make_map(char *filename, int total_row, int total_col, char *base)
{
	int		fd;
	int		i;
	int		**ans;
	char	buf[1];

	ans = (int **)malloc(sizeof(int *) * total_row);
	if (!ans)
		return (0);
	i = -1;
	while (++i < total_row)
	{
		ans[i] = (int *)malloc(sizeof(int) * total_col);
		if (!ans[i])
			return (0);
	}
	fd = open(filename, O_RDONLY);
	while (1)
	{
		read(fd, buf, 1);
		if (*buf == '\n')
			break ;
	}
	return (make_map2(ans, fd, base));
}
