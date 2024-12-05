#include <stdarg.h>
#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_start(args, format);
	int	i;
	
	i = 0;
	while (format[i])
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
		ft_putchar(*format);
		format++;	
	}
	return (i);
}

int	main(void)
{
	char *str = "Milva";
	int integer = -28;
	unsigned int u_int = 98;
	char letter = 'M';
	void *ptr = &str;
	ft_printf("Stringa: %s\nIntero: %i\nDecimale: %d\nEsadecimale minuscolo: %x\nEsadecimale maiuscolo: %X\nCarattere: %c\nPointer: %p\nUnsigned: %u\n", str, integer, integer, integer, integer, letter, ptr, u_int);
	ft_printf("Sono solo una stringa");
	return 0;
}	
