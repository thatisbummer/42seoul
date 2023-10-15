#include "ft.h"

int	open_stdin(void)
{
	int		fd;
	char	buf[1];

	fd = open("map.txt", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		return (0);
	while (read(0, buf, 1))
		write(fd, buf, 1);
	close(fd);
	return (1);
}

void	make_stdin(int *argc, char *argv[])
{
	if (open_stdin() == 1)
	{
		*argc = 2;
		argv[1] = "map.txt";
	}
}
