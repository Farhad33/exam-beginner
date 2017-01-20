#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_copy(char *str, char *s, int i, int j)
{
	while ((s[i] == ' ' || s[i] == '\t') && s[i])
		i++;
	while ((s[i] != ' ' && s[i] != '\t') && s[i])
		i++;
	while ((s[i] == ' ' || s[i] == '\t') && s[i])
		i++;
	while ((s[i] != ' ' && s[i] != '\t') && s[i])
		str[j++] = s[i++];
	while (s[i])
	{
		while ((s[i] == ' ' || s[i] == '\t') && s[i])
			i++;
		if ((s[i] != ' ' && s[i] != '\t') && s[i])
			str[j++] = ' ';
		while ((s[i] != ' ' && s[i] != '\t') && s[i])
			str[j++] = s[i++];
	}
	i = 0;
	while ((s[i] == ' ' || s[i] == '\t') && s[i])
		i++;
	if ((s[i] != ' ' && s[i] != '\t') && s[i])
		str[j++] = ' ';
	while ((s[i] != ' ' && s[i] != '\t') && s[i])
		str[j++] = s[i++];
	str[j] = '\0';
}

int		main(int argc, char **argv)
{
	int		len;
	char	*str;
	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	len = ft_strlen(argv[1]);
	if (!(str = malloc(sizeof(str) * (len + 1))))
		return (0);
	ft_copy(str, argv[1], 0, 0);
	ft_putstr(str);
	free(str);
	ft_putchar('\n');
	return (0);
}
