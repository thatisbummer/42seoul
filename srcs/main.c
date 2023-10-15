#include "ft.h"

void	set_total(t_total *total)
{
	total->col = 0;
	total->row = 0;
}

void	set_idx(t_idx *idx, int argc)
{
	idx->i = 1;
	idx->argc = argc;
}

void	print_answer(int **ans, t_total total, char *base, t_idx *idx)
{
	set_ans(ans, total.row, total.col);
	print_ans(ans, total.row, total.col, base);
	free_ans(ans, total.row);
	if (idx->i != idx->argc - 1)
		write(1, "\n", 1);
	(idx->i)++;
}

void	print_error(t_idx *idx)
{
	write(1, "map error\n", 10);
	if (idx->i != idx->argc - 1)
		write(1, "\n", 1);
	(idx->i)++;
}

int	main(int argc, char *argv[])
{
	t_idx	idx;
	t_total	total;
	int		**ans;
	char	base[3];

	if (argc == 1)
		make_stdin(&argc, argv);
	set_idx(&idx, argc);
	while (idx.i < argc)
	{
		set_total(&total);
		if (read_row_base(argv[idx.i], &total.row, base))
		{
			if (read_map(argv[idx.i], &total.row, &total.col, base))
			{
				ans = make_map(argv[idx.i], total.row, total.col, base);
				if (!ans)
					return (0);
				print_answer(ans, total, base, &idx);
				continue ;
			}
		}
		print_error(&idx);
	}
	return (0);
}
