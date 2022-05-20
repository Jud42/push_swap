#include "./include/ft_printf.h"
#include <stdio.h>
int	main(void)
{
	int n = -1;
	ft_printf("%p\n", n);
	printf("%p\n", &n);
	return 0;
}
