#include "ft.h"

int	read_map2(int fd, int *total_col, char *base, int *row)
{
	int		col;
	char	buf[1];

	col = 0;
	while (read(fd, buf, 1))
	{
		if (!map_check(*buf, *row, col, base))
			return (0);
		if (*buf != '\n')
			col++;
		if (*buf == '\n')
		{
			if (*total_col != col && *row > 0)
				return (0);
			(*row)++;
			*total_col = col;
			col = 0;
		}
	}
	return (1);
}

int	skip(char *filename)
{
	int		fd;
	char	buf[1];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	while (1)
	{
		read(fd, buf, 1);
		if (*buf == '\n')
			break ;
	}
	return (fd);
}

int	read_map(char *filename, int *total_row, int *total_col, char *base)
{
	int		fd;
	int		row;

	fd = skip(filename);
	row = 0;
	if (read_map2(fd, total_col, base, &row) == 0)
	{
		close(fd);
		return (0);
	}
	if (*total_row != row)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
