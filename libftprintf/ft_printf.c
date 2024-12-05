#include <stdarg.h>
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_start(args, format);
	int	i;
	
	i = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			if (*format == 'c')
				ft_putchar(va_arg(args, int));
			else if (*format == 's')
				ft_putstr(va_arg(args, char *));
			else if (*format == 'd')
				ft_putnbr(va_arg(args, int));
			else if (*format == 'i')
				ft_putnbr(va_arg(args, int));
			else if (*format == 'u')
				ft_putnbr_unsigned(va_arg(args, unsigned int));
			else if (*format == 'x')
				ft_putnbr_hex(va_arg(args, int));
			else if (*format == 'X')
				ft_putnbr_HEX(va_arg(args, int));
			else if (*format == 'i')
				ft_putnbr(va_arg(args, int));
			else if (*format == 'p')
				ft_putptr(va_arg(args, void *));
			else if (*format == '%')
				ft_putchar('%');
			format++;
		}
		if (*format)
		{
			ft_putchar(*format);
			format++;
		}
	}
	return (i);
}
/*
int	main(void)
{
	ft_printf(" %c %c %c \n", 0, '1', '2');
	printf(" %c %c %c ", 0, '1', '2');
	return 0;
}
*/
