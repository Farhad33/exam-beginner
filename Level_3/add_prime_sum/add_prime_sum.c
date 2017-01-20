#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar(*s++);
}

int		ft_isspace(int c)
{
	if (c == ' ' ||
		c == '\r' ||
		c == '\f' ||
		c == '\t' ||
		c == '\v' ||
		c == '\n')
	{
		return (1);
	}
	return (0);
}

size_t		ft_checknum(char *s, size_t re, int neg, int pos)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-' && (s[i + 1] >= 48 && s[i + 1] <= 57))
			neg = 1;
		if (s[i] == '+' && (s[i + 1] >= 48 && s[i + 1] <= 57))
			pos = 1;
		if (s[i] >= 48 && s[i] <= 57)
		{
			re = re * 10 + (s[i] - '0');
			if (!(s[i + 1] >= 48 && s[i + 1] <= 57))
				break ;
		}
		else if (!(ft_isspace(s[i])) && (!neg && !pos))
			break ;
		i++;
	}
	if (neg)
		re = -re;
	return (re);
}

void	ft_putnbr(int nb)
{
	if (nb > 2147483647 || nb < -2147483648)
		return ;
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-');
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
}

int		ft_atoi(char *s)
{
	int result;

	result = ft_checknum(s, 0, 0, 0);
	return (result);
}

int		is_prime(int num)
{
	int i;

	if (num == 2)
		return (1);
	if (!(num % 2))
		return (0);
	i = 3;
	while (num >= i)
	{
		if (!(num % i))
			return (0);
		i += 2;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int num;
	int sum;

	sum = 0;
	if (argc != 2 || (num = ft_atoi(argv[1])) < 1)
	{
		write(1, "0\n", 2);
		return (0);
	}
	while (num > 1)
	{
		if (is_prime(num))
		{

			sum += num;
			ft_putnbr(num);
			write(1, "\n", 1);
			ft_putnbr(sum);
			write(1, "\n", 1);
			write(1, "\n", 1);
		}
		num--;
	}
	// ft_putnbr(sum);
	// write(1, "\n", 1);
	return (0);
}
