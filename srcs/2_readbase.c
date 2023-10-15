#include "ft.h"

int	read_row_base(char *filename, int *total_row, char *base)
{
	int		fd;
	char	info[20];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!read(fd, info, 20))
	{
		close(fd);
		return (0);
	}
	if (base_check(info, total_row, base))
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int	double_check(char *info, int *i)
{
	(*i)--;
	if (info[*i] == info[*i - 1]
		|| info[*i] == info[*i - 2]
		|| info[*i - 1] == info[*i - 2])
		return (0);
	else
		(*i) -= 3;
	return (1);
}

int	num_check(char *info, int i)
{
	if (!(info[i] >= '0' && info[i] <= '9'))
		return (0);
	return (1);
}

void	set_base_row(char *info, int pos, int *total_row, char *base)
{
	int	i;
	int	j;

	i = pos + 1;
	j = 0;
	while (info[i] != '\n')
		base[j++] = info[i++];
	base[j] = '\0';
	i = 0;
	while (i <= pos)
		*total_row = *total_row * 10 + info[i++] - '0';
}

int	base_check(char *info, int *total_row, char *base)
{
	int	i;
	int	pos;

	i = 0;
	while (info[i] != '\n')
	{
		if (!(info[i] >= 32 && info[i] <= 126))
			return (0);
		i++;
	}
	if (i < 4)
		return (0);
	if (!double_check(info, &i))
		return (0);
	pos = i;
	while (i >= 0)
	{
		if (!num_check(info, i))
			return (0);
		i--;
	}
	set_base_row(info, pos, total_row, base);
	return (1);
}
