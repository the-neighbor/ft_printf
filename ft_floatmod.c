#include "libft.h"

long double		ft_floatmod(long double alpha, long double beta)
{
	long double		temp;
	long long		counter;

	temp = 0;
	counter = 0;
	while (alpha - temp >= 0)
	{
		temp = beta * counter;
		++counter;
		printf("temp is: %Lf\n", temp);
	}
	if (alpha - temp < 0)
		temp = beta * (counter - 2);
	printf("temp is: %Lf\n", temp);
	return (alpha - temp);
}