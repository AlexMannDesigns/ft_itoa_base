#include <stdlib.h>
#include <stdio.h>
//convert int to null terminated string, in dynamically allocated char array
//base is expressed as an int: 2 - 16
//Always unsigned, unless base 10


char	*ft_itoa_base(int value, int base)
{
	char	*res;
	int	sign;

	sign = 0;
	if (base == 10 && value < 0)
		sign = 1;
	return (res);
}

int	main(void)
{
	printf("%s\n", ft_itoa_base(42, 2));
	printf("%s\n", ft_itoa_base(42, 10));
	printf("%s\n", ft_itoa_base(42, 16));
	printf("%s\n", ft_itoa_base(-42, 7));
	printf("%s\n", ft_itoa_base(-42, 10));
}
