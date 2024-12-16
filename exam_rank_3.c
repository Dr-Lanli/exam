#include <unistd.h>
#include <stdarg.h>

int ft_putnbr(int n)
{
	int len = 0;
	if (n < 0)
	{
		write(1, &"-", 1);
		n = -n;
	}
	if (n > 9)
	{
		len += ft_putnbr(n / 10);
	}
	write(1, &"0123456789"[n % 10], 1);
	len++;
	return (len);
}

int ft_puthex(int n)
{
	int len = 0;

	if (n >= 16)
	{
		len += ft_puthex(n / 16);
	}
	write(1, &"0123456789abcdef"[n % 16], 1);
	len++;
	return (len);
}

int ft_putstr(char *str)
{
	int len = 0;

	while (str && *str)
	{
		str++;
		len++;
	}
	return (len);
}

int spec_char(va_list args, const char *str)
{
	int len = 0;

	if (*str == 'd')
	{
		len = ft_putnbr(va_arg(args, int));
	}
	else if (*str == 's')
	{
		len = ft_putstr(va_arg(args, char *));
	}
	else if (*str == 'x')
	{
		len = ft_puthex(va_arg(args, unsigned int));
	}
	return (len);
}

int ft_printf(const char *str, ...)
{
	int len = 0;
	va_list args;

	va_start(args, str);
	while (str && *str)
	{
		if (*str == '%')
		{
			str++;
			len += spec_char(args, str);
		}
		else
		{
			write(1, str, 1);
			len++;
		}
		str++;
	}
	va_end(args);
	return (len);
}

#include <stdio.h>
int main()
{
	//ft_putstr("ceci est un test");
	//ft_puthex(42);
	//printf("%d\n", ft_puthex(42));
	char *string = "hello";
	int n = 42;
	//ft_printf("test: %s", test);
	ft_printf("lenght ft_printf: %d\n", ft_printf("test: %x\n", n));
	printf("lenght printf: %d\n", printf("test: %x\n", n));

	return (0);
}