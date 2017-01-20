#include <unistd.h>

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		main(int argc, char **s)
{
	int i;
	int j;

	i = 0;
	if (argc != 2 || (j = ft_strlen(s[1])) == 0)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (s[1][i] == ' ' || s[1][i] == '\t')
		i++;
	j--;
	while (s[1][j] == ' ' || s[1][j] == '\t')
		j--;
	while (i <= j)
	{
		while (s[1][i] != ' ' && s[1][i] != '\t')
		{
			write(1, &s[1][i], 1);
			i++;
		}
		if (s[1][i + 1] != ' ' && s[1][i + 1] != '\t' && s[1][i + 1])
			write(1, " ", 1);
		i++;
	}
	return (0);
}
