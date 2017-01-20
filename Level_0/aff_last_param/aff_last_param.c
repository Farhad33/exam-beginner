#include <unistd.h>

int		main(int argc, char **argv)
{
	int i;
	int j;

	if (argc > 1)
	{
		j = 0;
		while (argv[j])
		{
			if (argv[j + 1] == '\0')
				break ;
			j++;
		}
		i = 0;
		while (argv[j][i])
		{
			write(1, &argv[j][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
