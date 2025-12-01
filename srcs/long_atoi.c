#include "push_swap.h"

static long int	sign_nbr(char *nptr, long int i)
{
	long int	sign;

	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		if (nptr[i + 1] == '-' || nptr[i +1] == '+')
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (sign);
}

long int	ft_long_atoi(char *nptr)
{
	long int	i;
	long int	n;
	long int	sign;

	i = 0;
	n = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	sign = sign_nbr(nptr, i);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = 10 * n + (nptr[i] - '0');
		if (n < INT_MIN || n > INT_MAX)
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (n * sign);
}
