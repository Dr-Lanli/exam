#include <unistd.h>
#include <stdarg.h>

int ft_putnbr(int n)
{
	int len = 0;

    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }
    if (n > 9)
    {
        ft_putnbr(n / 10);
    }
	len++;
    write(1, &"0123456789"[n % 10], 1);
	return (len);
}

int ft_puthex(int n)
{
	static int len = 0;
    if (n >= 16)
    {
		len++;
        ft_putnbr(n / 16);
    }
	write(1, &"0", 1);
    write(1, &"0123456789abcdef"[n % 16], 1);
	len +=2;
	return (len);
}

int ft_putstr(char *str)
{
	int len = 0;
	if (!str)
	{
		return (0);
	}
	while (*str)
	{
		write(1, str++, 1);
		len++;
	}
	return (len);
}

int spec_char(va_list args, const char *str)
{
	int len;

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
	va_list args;
	int i = 0;
	int len = 0;

	va_start(args, str);
	while (str)
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
	return(len);
}

#include <stdio.h>
int main()
{
	//ft_putstr("ceci est un test");
	printf("%d\n", ft_puthex(15));
	return (0);
}
