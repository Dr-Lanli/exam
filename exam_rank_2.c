/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <lmonsat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:16:35 by lmonsat           #+#    #+#             */
/*   Updated: 2024/05/06 18:17:30 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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
}