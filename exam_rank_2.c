/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam_rank_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <lmonsat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:16:35 by lmonsat           #+#    #+#             */
/*   Updated: 2024/05/07 16:41:57 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/* Level 1 */

void ft_putnbr(int n)
{
    if (n > 9)
    {
        ft_putnbr(n / 10);
    }
    write(1, &"0123456789"[n % 10], 1);
}
void fizz_buzz()
{
    int i;

    i = 0;

    while (i <= 100)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            write(1,"fizzbuzz", 8);
        }
        else if (i % 3 == 0)
        {
            write(1,"fizz", 4);
        }
        else if (i % 5 == 0)
        {
             write(1,"buzz", 4);
        }
        else
        {
            ft_putnbr(i);
        }
        i++;
        write(1, "\n", 1);
    }

}

void repeat_alpha(int argc, char *argv[])
{
    int i;
    int j;

    if (argc == 2)
    {
        i = 0;
        while (argv[1][i])
        {
            if (argv[1][i] >= 65 && argv[1][i] <= 90)
            {
                j = 0;
                while (j < argv[1][i] - 64)
                {
                    write(1, &argv[1][i], 1);
                    j++;
                }
            }
            else if (argv[1][i] >= 97 && argv[1][i] <= 122)
            {
                j = 0;
                while (j < argv[1][i] - 96)
                {
                    write(1, &argv[1][i], 1);
                    j++;
                }
            }
            else
            {
                write(1, &argv[1][i], 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);
}

void search_and_replace(int argc, char *argv[])
{
    int i;

    i = 0;

    if (argc == 4)
    {
        while (argv[1][i])
        {
            if (argv[1][i] == argv[2][0])
            {
                argv[1][i] = argv[3][0];
            }
            write(1, &argv[1][i],1);
            i++;
        }
    }
    write(1, "\n", 1);
}
void ulstr(int argc, char *argv[])
{
    int i;

    i = 0;

    if (argc == 2)
    {
        while (argv[1][i])
        {
            if (argv[1][i] >= 65 && argv[1][i] <= 90)
            {
                argv[1][i] += 32;
            }
            else if (argv[1][i] >= 97 && argv[1][i] <= 122)
            {
                argv[1][i] -= 32;
            }
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}

/* Level 2 */

void alpha_mirror(int argc, char *argv[])
{
    int i;

    if (argc == 2)
    {
        i = 0;
        while (argv[1][i])
        {
            if (argv[1][i] >= 65 && argv[1][i] <= 90)
            {
                argv[1][i] = 90 - argv[1][i] + 65;
            }
            else if (argv[1][i] >= 97 && argv[1][i] <= 122)
            {
                argv[1][i] = 122 - argv[1][i] + 97;
            }
            write(1, &argv[1][i],1);
            i++;
        }
    }
    write(1, "\n", 1);
}

void camel_to_snake(int argc, char *argv[])
{
    int i;

    if (argc == 2)
    {
        i = 0;
        while (argv[1][i])
        {
            if (argv[1][i] >= 65 && argv[1][i] <= 90 )
            {
                argv[1][i] += 32;
                write(1, "_", 1);
            }
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}

void do_op(int argc, char *argv[])
{
    if (argc == 4)
    {
        switch (argv[2][0])
        {
        case '+':
            printf("%d", atoi(argv[1]) + atoi(argv[3]));
            break;
        
        case '-':
            printf("%d", atoi(argv[1]) - atoi(argv[3]));
            break;
        
        case '*':
            printf("%d", atoi(argv[1]) * atoi(argv[3]));
            break;
        
        case '/':
            printf("%d", atoi(argv[1]) / atoi(argv[3]));
            break;
        
        case '%':
            printf("%d", atoi(argv[1]) % atoi(argv[3]));
            break;
        
        default:
            break;
        }
    }
    printf("\n");
}

int ft_atoi(const char *str)
{
	int i;
	int is_negative;
	int n;

	i = 0;
	is_negative = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		is_negative = 1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i++] - '0';
	}
	if (is_negative)
	{
		return (-n);
	}
	else
	{
		return (n);
	}
	
}

void print_bit(unsigned char octet)
{
    int i = 8;
    unsigned char bit = 0;


    while (i--)
    {
        bit = (octet >> i & 1) + 48;
        write(1, &bit, 1);
    }
    
}


size_t ft_strcspn(const char *s, const char *reject)
{
    int i;
    int j;

    i = 0;
    while (s[i])
    {
        j = 0;
        while (reject[j])
        {
            if (s[i] == reject[j])
            {
                return (i);
            }
            j++;
        }
        i++;
    }
    return (i);
}

size_t	ft_strspn(const char *s, const char *accept)
{
    int i;
    int j;
    int bytes_in_accept;

    i = 0;
    while (s[i])
    {
        j = 0;
        bytes_in_accept = 0;
        while (accept[j])
        {
            if (s[i] == accept[j])
            {
                bytes_in_accept = 1;
            }
            j++;
        }
        if (bytes_in_accept == 0)
        {
            return (i);
        }
        i++;
    }
    return (i);
}

char    *ft_strdup(char *src)
{
    char *src_mem;
    int len;
    int i;

    len = 0;
    while (src[len])
    {
        len++;
    }
    src_mem = malloc ((len + 1) * sizeof(char));
    if (src_mem == NULL)
    {
        return(NULL);
    }
    i = 0;
    while (src[i])
    {
        src_mem[i] = src[i];
        i++;
    }
    src_mem[i] = 0;
    return (src_mem);
}

char	*ft_strpbrk(const char *s1, const char *s2)
{
    int i;
    int j;

    i = 0;
    while (s1[i])
    {
        j = 0;
        while (s2[j])
        {
            if (s1[i] == s2[j])
            {
                return (s1[i]);
            }
            j++;
        }
        i++;
    }
    return (NULL);    
}


char    *ft_strrev(char *str)
{
    char temp;
    int len;
    int i;

    len = 0;
    i = 0;
    while (str[len])
    {
        len++;
    }
    while (i < len -1)
    {
        temp = str[i];
        str[i] = str[len - 1];
        str[len - 1] = temp;
        len--;
        i++;
    }
    return(str);
}
void last_world(int argc, char *argv[])
{
    int i;

    i = 0;
    if (argc == 2)
    {
        while (argv[1][i])
        {
            i++;
        }
        i--;
        while (argv[1][i] > 32)
        {
            i--;
        }
        i++;
        while (argv[1][i])
        {
            write(1, &argv[1][i++], 1);
        }
    }
}


int main (int argc, char *argv[])
{
    //do_op(argc, argv);
    //alpha_mirror(argc, argv);
    //camel_to_snake(argc, argv);
    //ft_putnbr(255);
    //fizz_buzz();
    //repeat_alpha(argc, argv);
    //search_and_replace(argc, argv);
    //ulstr(argc, argv);

	/*char *s = "hello";
	const char *accept = "jfkhpell";
	printf("%zu\n", ft_strspn(s, accept));

    char *s2 = "hello";
	const char *accept2 = "jfkhpell";
	printf("%zu\n", strspn(s2, accept2));*/

    //printf("%s\n", ft_strdup("Hello, World!"));

	/*char ss[] = "Hello, World!";
	ft_strrev(ss);
	printf("%s\n", ss);*/

    //last_world(argc, argv);


}