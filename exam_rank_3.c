
/* -------------- PRINTF ------------- */

#pragma region PRINTF
/*
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int ft_putnbr(int n)
{
	int len = 0;

	if (n == -2147483648)
    {
        write(1, &"-2147483648", 11);
        return (11);
    }
	if (n < 0)
	{
		write(1, &"-", 1);
		n = -n;
		len++;
	}
	if (n > 9)
	{
		len += ft_putnbr(n / 10);
	}
	write(1, &"0123456789"[n % 10], 1);
	len++;
	return (len);
}

int ft_puthex(unsigned int n)
{
	int len = 0;

    if (n >= 16)
        len += ft_puthex(n / 16);
    write(1, &"0123456789abcdef"[n % 16], 1);
	len++;
	return (len);
}

int ft_putstr(char *str)
{
	int len = 0;
    if (!str)
    {
        write(1, "(null)", 6);
        return (6);
    }
	while (str && *str)
	{
		write(1, str++, 1);
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
    else
    {
        write(1, str, 1);
        len++;
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
*/
#pragma endregion

/* ---------- GET_NEXT_LINE ---------- */

#pragma region GET_NEXT_LINE

#include "get_next_line.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (src[i])
	{
	   dest[i] = src[i];
	   i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		line[70000];
	static int	buffer_read;
	static int 	buffer_pos;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_pos >= buffer_read)
		{
			buffer_read = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_read <= 0)
				break ;
		}
		line[i++] = buffer[buffer_pos];
		if (buffer[buffer_pos++] == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}
/*
int main()
{
    int fd = open("./test.txt", O_RDONLY);
    	char *result = get_next_line(fd);
	printf("next line '%s'\n", result);

		char *result2 = get_next_line(fd);
	printf("next line '%s'\n", result2);

		char *result3 = get_next_line(fd);
	printf("next line '%s'\n", result3);

		char *result4 = get_next_line(fd);
	printf("next line '%s'\n", result4);

		char *result5 = get_next_line(fd);
	printf("next line '%s'\n", result5);

		char *result6 = get_next_line(fd);
	printf("next line '%s'\n", result6);
	close(fd);
    return (0);
}*/
#pragma endregion