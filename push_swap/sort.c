#include "push_swap.h"

int		max_of_three(int a, int b, int c)
{
	int	max;

	max = a;
	if (a < b)
	{
		max = b;
		if (b < c)
			max = c;
	}
	else if (a < c)
		max = c;
	return (max);
}


