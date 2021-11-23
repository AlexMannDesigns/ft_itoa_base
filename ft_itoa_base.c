#include <stdlib.h>
#include <stdio.h>
//convert int to null terminated string, in dynamically allocated char array
//base is expressed as an int: 2 - 16
//Always unsigned, unless base 10

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}


char	*itoa_realloc(char *str)
{
	int	len;
	int	i;
	char	temp;
	len = ft_strlen(str) - 1;
	i = 0;
	while (i <= (len/2))
	{
		temp = str[i];
		str[i] = str[len - i];
		str[len - i] = temp;
		i++;
	}
	return (str);
}

char	*itoa_helper_neg(int nb, int base, char *res)
{
	char	*arr;
	int	i;

	arr = "0123456789ABCDEF";
	i = 0;
	while (nb >= 1)
	{
		res[i] = arr[nb % base];
		nb = nb / base;
		i++;
	}
	res[i] = '-';
	res[i + 1] = '\0';
	return (res);
}

char	*itoa_helper(int nb, int base, char *res)
{
	char	*arr;
	int	i;

	arr = "0123456789ABCDEF";
	i = 0;
	while (nb > 0)
	{
		res[i] = arr[nb % base];
		nb = nb / base;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_itoa_base(int value, int base)
{
	char	*res;
	int 	i;
	int	n;

	n = value;
	i = 0;
	while ( n / base > 0)
	{	
		n = n / base;
		i++;
	}
	if (value < 0 && base == 10)
		res = (char *) malloc(sizeof(char) * (i + 1));
	else
		res = (char *) malloc(sizeof(char) * i);
	if (value < 0)
	{
		value = value * -1;
		if (base == 10)
			res = itoa_helper_neg(value, base, res);
		else
			res = itoa_helper(value, base, res);
	}
	else
		res = itoa_helper(value, base, res);		
	res = itoa_realloc(res);
	return (res);
}

int	main(void)
{
	printf("base 2: %s\n", ft_itoa_base(42, 2));
	printf("base 10: %s\n", ft_itoa_base(42, 10));
	printf("base 16: %s\n", ft_itoa_base(42, 16));
	printf("base 7, neg: %s\n", ft_itoa_base(-42, 7));
	printf("base 10, neg: %s\n", ft_itoa_base(-42, 10));
	printf("base 2: %s\n", ft_itoa_base(42521, 2));
	printf("base 10: %s\n", ft_itoa_base(42521, 10));
	printf("base 16: %s\n", ft_itoa_base(42521, 16));
	printf("base 7, neg: %s\n", ft_itoa_base(-42521, 7));
	printf("base 10, neg: %s\n", ft_itoa_base(-42521, 10));
	
	return (0);
}
