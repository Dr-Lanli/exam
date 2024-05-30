/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam_rank_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <lmonsat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:16:35 by lmonsat           #+#    #+#             */
/*   Updated: 2024/05/30 19:47:32 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/* ---- Level 1 ---- */
#pragma region Level_1

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

#pragma endregion

/* ---- Level 2 ---- */
#pragma region Level_2
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

void snake_to_camel(int argc, char *argv[])
{
    int i;

    if (argc == 2)
    {
        i = 0;
        while (argv[1][i])
        {
            if (argv[1][i] == *"_")
            {
                argv[1][i + 1] -= 32;
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

int ft_strcmp(char *s1, char *s2)
{
    int i;
    
    i = 0;
    while ((s1[i] || s2[i]) && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
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
    int check;

    i = 0;
    while (s[i])
    {
        j = 0;
        check = 0;
        while (accept[j])
        {
            if (s[i] == accept[j])
            {
                check = 1;
            }
            j++;
        }
        if (check == 0)
        {
            return (i);
        }
        i++;
    }
    return (i);
}

char *ft_strdup(char *src)
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

char *ft_strpbrk(const char *s1, const char *s2)
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


char *ft_strrev(char *str)
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
    while (i < len - 1)
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

int is_power_of_2(unsigned int n)
{
    int i;

    i = 1;
    while (i <= n)
    {
        i = i * 2;
        if (i == n)
        {
            return (1);
        }
    }
    return (0);
}

int	ft_max(int* tab, unsigned int len)
{
    int count;
    int result;
    int i;

    i = 0;
    result = 0;
    if (len > 0)
    {
        while (i < len)
        {
            if (result < tab[i])
            {
                result = tab[i];
            }
            i++;
        }
        return (result);
    }
    return (0); 
}

int wdmatch(int argc, char *argv[])
{
    const char *s1 = argv[1];
    const char *s2 = argv[2];
    int len = 0;
    int i = 0;
    
    while (s1[len])
    {
        len++;
    }
    while (i < len && *s2)
    {
        if (s1[i] == *s2++)
        {
            i++;
        }
    }

    if (i == len)
    {
        write(1, s1, len);
    }
    return (0);
}

void print_bits(unsigned char octet)
{
    int i = 8;
    int bit = 0;

    while (i--)
    {
        bit = (octet >> i & 1) + 48;
        write(1, &bit, 1);
    }
    
}

unsigned char reverse_bits(unsigned char octet)
{
    int i = 8;
    unsigned char bit = 0;

    while (i--)
    {
        bit = bit * 2 + (octet % 2);
        octet = octet / 2;
    } 
    return (bit);
}

unsigned char swap_bits(unsigned char octet)
{
    return((octet >> 4) | (octet << 4));
}

void ft_union(int argc, char *argv[])
{
    int i = 0;
    int lookup[256] = {0};

    if (argc == 3)
    {
        while (argv[1][i])
        {
            lookup[(int)argv[1][i++]] = 1;
        }

        i = 0;
        while (argv[2][i])
        {
            lookup[(int)argv[2][i++]] = 1;
        }
        i = 0;

        while (argv[1][i])
        {
            if (lookup[(int)argv[1][i]])
            {
                write(1, &argv[1][i], 1);
                lookup[(int)argv[1][i]] = 0;
            }
            i++;
        }
        i = 0;

        while (argv[2][i])
        {
            if (lookup[(int)argv[2][i]])
            {
                write(1, &argv[2][i], 1);
                lookup[(int)argv[2][i]] = 0;
            }
            i++;
        }
    }
    write(1, "\n", 1);
}

void ft_inter(int argc, char *argv[])
{
	if (argc == 3)
	{
		int	lookup[256] = {0};
		int	i = 0;

		while (argv[1][i])
		{
			int j = 0;
			while (argv[2][j])
			{
				if (argv[1][i] == argv[2][j] && !lookup[(int)argv[1][i]])
				{
					lookup[(int)argv[1][i]] = 1;
					write(1, &argv[1][i], 1);
					break;
				}
				j++;
			}
			i++;
		}
	}
    write(1, "\n", 1);
}

#pragma endregion

/* ---- Level 3 ---- */
#pragma region Level_3

int is_space(char c)
{
    if (c <= 32)
    {
        return (1);
    }
    return (0);
}

void epur_str(int argc, char *argv[])
{
    int i = 0;
    int space = 0;

    if (argc == 2)
    {
        while (is_space(argv[1][i]))
        {
            i++;
        }
        while (argv[1][i])
        {
            if (is_space(argv[1][i]))
            {
                space = 1;
            }
            
            if (!is_space(argv[1][i]))
            {
                if (space)
                {
                    write(1, &" ", 1);
                }
                space = 0;
                write(1, &argv[1][i], 1);
            }
            i++;
        }   
    }
    write(1, &"\n", 1);
}

void expand_str(int argc, char *argv[])
{
    int i = 0;
    int space = 0;

    if (argc == 2)
    {
        while (is_space(argv[1][i]))
        {
            i++;
        }
        while (argv[1][i])
        {
            if (is_space(argv[1][i]))
            {
                space = 1;
            }
            
            if (!is_space(argv[1][i]))
            {
                if (space)
                {
                    write(1, &"   ", 1);
                }
                space = 0;
                write(1, &argv[1][i], 1);
            }
            i++;
        }   
    }
}

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list)
{
    int i = 0;

    while (begin_list->next)
    {
        begin_list = begin_list->next;
        i++;
    }
    return (i);
}

int *ft_range(int start, int end)
{
    int i = 0;
    int len = (end - start) < 0 ? ((end - start) * - 1) + 1 : (end - start) + 1;
    int *res = (int *)malloc(len * sizeof(int));

    while (i < len)
    {
        if (start < len)
        {
            res[i] = start;
            start++;
            i++;
        }
        else
        {
            res[i] = start;
            start--;
            i++;
        }
    }
    return (res);
}

int *ft_rrange(int start, int end)
{
    int i = 0;
    int len = (end - start) < 0 ? ((end - start) * - 1) + 1 : (end - start) + 1;
    int *res = (int *)malloc(len * sizeof(int));

    while (i < len)
    {
        if (end < start)
        {
            res[i] = end;
            end++;
            i++;
        }
        else
        {
            res[i] = end;
            end--;
            i++;
        }
    }
    return (res);
}

void hidenp(int argc, char *argv[])
{
    int i = 0;
    int j = 0;
    if (argc == 3)
    {
        while (argv[2][j] && argv[1][i])
        {
            if (argv[2][j] == argv[1][i])
            {
                i++;
            }
            j++;
        }
        if (argv[1][i] == 0)
        {
            write(1, "1", 1);
        }
        else
        {
            write(1, "0", 1);
        }
    }
    while (argv[2][j] && argv[1][i])
    {
        if (argv[2][j] == argv[1][i])
        {
            i++;
        }
        j++;
    }
    if (argv[1][i] == 0)
    {
        write(1, "1", 1);
    }
    else
    {
        write(1, "0", 1);
    }
    write(1, "\n", 1);
}

unsigned int lcm(unsigned int a, unsigned int b)
{
    unsigned int g = (a < b) ? a : b;

    while (1)
    {
        if ((g % a == 0) && (g % b == 0))
        {
            return (g);
        }
        g++;
    }    
}

void parasum(int argc, char *argv[])
{
    (void)argv;

    ft_putnbr(argc - 1);
    write(1, "\n", 1);
}

void pgcd(int argc, char*argv[])
{
    int number1 = atoi(argv[1]);
    int number2 = atoi(argv[2]);

    if (argc == 3)
    {
        if (number1 > 0 && number2 > 0)
        {
            while (number1 != number2)
            {
                if (number1 > number2)
                {
                    number1 -= number2;
                }
                else
                {
                    number2 -= number1;
                }
            }
        printf("%d", number1);
        }
    }
    printf("\n");
}

int ft_atoi2(const char *str)
{
    int i = 0;
    int is_negative = 0;
    int n = 0;

    while (str[i] == " ")
    {
        i++;
    }
    if (str[i] == "-")
    {
        i++;
        is_negative = 1;
    }
    else if (str[i] == "+")
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

void put_hex(int n)
{
    if (n >= 16)
    {
        put_hex(n / 16);
    }
    write(1, &"0123456789abcdef"[n % 16], 1);
    
}

void print_hex(int argc, char*argv[])
{
    if (argc == 2)
    {
        put_hex(ft_atoi2(argv[1]));
    }
    write(1, "\n", 1);
}

void r_capitalizer(char *s)
{
    int i = 0;

    while (s[i])
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] +=32;
        }
        if ((s[i] >= 'a' && s[i] <= 'z') && (is_space(s[i + 1])))
        {
            s[i] -=32;
        }
        write(1, &s[i++], 1);
    }
}

void exe_r_capitalizer(int argc, char *argv[])
{
    int i = 1;

    if (argc == 1)
    {
        write(1, &"\n", 1);
    }
    else
    {
        while (i < argc)
        {
            r_capitalizer(argv[i]);
            write(1, &"\n", 1);
            i++;
        }
    }
    
}

void str_capitalizer(char *s)
{
    int i = 0;

    while (s[i])
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] +=32;
        }
        if ((s[i] >= 'a' && s[i] <= 'z') && (is_space(s[i - 1])))
        {
            s[i] -=32;
        }
        write(1, &s[i++], 1);
    }
}

void exe_str_capitalizer(int argc, char *argv[])
{
    int i = 1;

    if (argc == 1)
    {
        write(1, &"\n", 1);
    }
    else
    {
        while (i < argc)
        {
            str_capitalizer(argv[i]);
            write(1, &"\n", 1);
            i++;
        }
    }
}

void put_str(const char *str)
{
    int i = 0;

    while (str[i])
    {
        write(1, &str[i++], 1);
    }
}

void tab_mult(int argc, char *argv[])
{
    if (argc != 2)
    {
        write(1, &"\n", 1);
    }

    int i = 1;
    int n = ft_atoi2(argv[1]);

    while (i < 10)
    {
        ft_putnbr(i);
        put_str(" x ");
        ft_putnbr(n);
        put_str(" = ");
        ft_putnbr(i * n);
        write(1, &"\n", 1);
        i++;
    }
}

#pragma endregion

/* ---- Level 4 ---- */
#pragma region Level_4

typedef struct  s_point
{
int           x;
int           y;
}               t_point;

void fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x || tab[cur.y][cur.x] != to_fill)
		return;
        
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}
void flood_fill(char **tab, t_point size, t_point begin)
{
    fill(tab, size, begin,tab[begin.x][begin.y]);
}

void f_prime(int argc, char *argv[])
{
    if (argc == 2)
    {
        int i = 0;
        int number = argv[1]; 
        if (number == 1)
        {
            printf("1");
        }
        while (number >= i++)
        {
            if (number % i == 0)
            {
                printf("%d", i);
                if (number == i)
                {
                    break ;
                }
                printf("*");
				number /= i;
				i = 1;
            }
        }
    }
    printf("\n");
}

void sort_int_tab(int *tab, unsigned int size)
{
    int temp = 0;
    int i = 0;

    while (i < (size - 1))
    {

        if (tab[i] > tab[i + 1])
        {
            temp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = temp;
        }
        else
        {
            i++;
        }
    }
}

#pragma endregion

int main (int argc, char *argv[])
{
    //do_op(argc, argv);
    //alpha_mirror(argc, argv);
    //camel_to_snake(argc, argv);
    snake_to_camel(argc, argv);
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

    //printf("%d", is_power_of_2(16));

    /*int int_tab[] = {1, 3, 2, 10, 9};
	printf("%d", ft_max(int_tab, 5));*/

    //wdmatch(argc, argv);

    //print_bits(15);

    //ft_union(argc, argv);

    //ft_inter(argc, argv);

    //epur_str(argc, argv);

    //expand_str(argc, argv);

    //pgcd(argc, argv);

    //exe_r_capitalizer(argc, argv);

    //exe_str_capitalizer(argc, argv);

    //tab_mult(argc, argv);
}