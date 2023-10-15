#include "ft.h"

int	check_map_base(char c, char *base)
{
	int	i;

	i = 0;
	if (c == '\n')
		return (1);
	while (i < 2)
		if (c == base[i++])
			return (1);
	return (0);
}

int	map_check(char c, int row, int col, char *base)
{
	if (row == 0 && col == 0 && c == '\n')
		return (0);
	if (!check_map_base(c, base))
		return (0);
	return (1);
}
