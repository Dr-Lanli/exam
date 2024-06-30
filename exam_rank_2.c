/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam_rank_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonsat <lmonsat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:16:35 by lmonsat           #+#    #+#             */
/*   Updated: 2024/07/01 00:36:34 by lmonsat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/* <----------------- Level 1 -----------------> */

#pragma region Level_1

void ft_putnbr(int n)
{
    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }
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

/* <----------------- Level 2 -----------------> */

#pragma region Level_2

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
    len--;
    while (i < len)
    {
        temp = str[i];
        str[i] = str[len];
        str[len] = temp;
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
					//break;
				}
				j++;
			}
			i++;
		}
	}
    write(1, "\n", 1);
}

#pragma endregion

/* <----------------- Level 3 -----------------> */

#pragma region Level_3

// Explication https://chatgpt.com/share/cfdef1fc-a1f3-4f72-8024-ff5fbdfc429f

int is_prime(int nbr)
{
    // Si le nombre est inférieur à 2, il n'est pas premier
    if (nbr < 2)
        return 0;

    int i = 2;

    // Parcourt tous les entiers de 2 à nbr/2
    while (i <= nbr / 2)
    {
        // Si nbr est divisible par i, alors nbr n'est pas premier
        if (nbr % i == 0)
            return 0; // Retourne 0 pour indiquer que nbr n'est pas premier
        i++;
    }

    // Si aucun diviseur n'a été trouvé, nbr est premier
    return 1; // Retourne 1 pour indiquer que nbr est premier
}

void add_prime_sum(int argc, char *argv[])
{
    // Vérifie que le nombre d'arguments est égal à 2 et que le deuxième argument est un entier positif
    if (argc != 2 || ft_atoi(argv[1]) <= 0)
    {
        // Si les conditions ne sont pas remplies, affiche "0" suivi d'un saut de ligne et quitte la fonction
        write(1, "0\n", 2);
        return;
    }

    // Convertit le deuxième argument en entier
    int n = ft_atoi(argv[1]);
    int sum = 0; // Initialise la variable sum à 0 pour stocker la somme des nombres premiers

    // Parcourt tous les entiers de n à 1
    while (n > 1)
    {
        // Vérifie si n est un nombre premier en appelant la fonction is_prime
        if (is_prime(n))
            sum += n; // Ajoute n à la somme si n est premier
        n--; // Décrémente n pour passer à l'entier précédent
    }

    // Affiche la somme calculée suivie d'un saut de ligne
    ft_putnbr(sum);
    write(1, "\n", 1);
}


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
        }
        else
        {
            res[i] = start;
            start--;
        }
        i++;
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
        }
        else
        {
            res[i] = end;
            end--;
        }
        i++;
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
        put_hex(ft_atoi(argv[1]));
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
    int n = ft_atoi(argv[1]);

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

/* <----------------- Level 4 -----------------> */

#pragma region Level_4

typedef struct  s_point
{
int           x;
int           y;
}               t_point;

void fill(char **tab, t_point size, char target, int row, int col)
{
    if (row < 0 || col < 0 || row >= size.y || col >= size.x)
        return ;

    if (tab[row][col] == 'F' || tab[row][col] != target)
        return ;

    tab[row][col] = 'F';

    fill(tab, size, target, row - 1, col);
    fill(tab, size, target, row + 1, col);
    fill(tab, size, target, row, col - 1);
    fill(tab, size, target, row, col + 1);
}

void flood_fill(char **tab, t_point size, t_point begin)
{
    char target = tab[begin.y][begin.x];
    fill(tab, size, target, begin.y, begin.x);
}
char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

char *ft_itoa(int nbr)
{
    if (nbr == -2147483648)
        return("-2147483648\0");

    // Calcul de la longueur nécessaire pour la chaîne
    
    int n = nbr;
    int len = 0;
    if (nbr <= 0)
        len++;
    while (n)
    {
        n /= 10;
        len++;
    }
    // Allocation
    char *result = (char *)malloc(sizeof(char) * (len + 1));
    if (result == NULL)
        return NULL;
    result[len] = '\0';

    // Gestion des cas particuliers pour zéro et les nombres négatifs
    
    if (nbr == 0)
    {
        result[0] = '0';
        return(result);
    }
    if (nbr < 0)
    {
        result[0] = '-';
        nbr = -nbr;
    }
    
    // Conversion des chiffres en caractères et remplissage de la chaîne

    while (nbr)
    {
        result[--len] = nbr % 10 + '0';
        nbr /= 10;
    }
    return (result);
}

// Explications https://chatgpt.com/share/b49475d5-3a65-47d6-9ee4-28a36231ae4e

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    while (begin_list)
    {
        (*f)(begin_list->data);
        begin_list = begin_list->next;
    }
}

// Explications https://chatgpt.com/share/4c3b7128-caf4-44dc-ab80-fca0c40de361

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    // Si le pointeur vers le début de la liste est NULL ou si la liste est vide, on ne fait rien.
    if (begin_list == NULL || *begin_list == NULL)
        return ;

    // Déclaration d'un pointeur cur pour parcourir la liste.
    t_list *cur = *begin_list;

    // Si la donnée du premier élément de la liste satisfait la condition spécifiée par cmp.
    if ((cmp)(cur->data, data_ref) == 0)
    {
        // On met à jour le début de la liste pour qu'il pointe vers le deuxième élément.
        *begin_list = cur->next;
        // On libère la mémoire de l'élément à supprimer.
        free(cur);
        // On appelle récursivement la fonction pour traiter le reste de la liste.
        ft_list_remove_if(begin_list, data_ref, cmp);
    }
    else
    {
        // Sinon, on avance dans la liste et on appelle récursivement la fonction sur l'élément suivant.
        cur = *begin_list;
        ft_list_remove_if(&cur->next, data_ref, cmp);
    }
}

// Explication https://chatgpt.com/share/00eb0c3e-cd8f-4fe4-b41a-7da6a4cb50ef

void f_prime(int argc, char *argv[])
{
    // Vérifie s'il y a exactement deux arguments (le nom du programme et un nombre)
    if (argc == 2)
    {
        int i = 2; // Initialisation du diviseur à 2 (le plus petit nombre premier)
        int number = atoi(argv[1]); // Convertit le deuxième argument en entier
        
        // Si le nombre est 1, on imprime "1"
        if (number == 1)
        {
            printf("1");
        }

        // Boucle pour trouver et imprimer les facteurs premiers du nombre
        while (number >= i)
        {
            // Si i est un facteur de number
            if (number % i == 0)
            {
                printf("%d", i); // Imprime le facteur

                // Si le nombre actuel est égal à i, il n'y a plus de facteurs à trouver
                if (number == i)
                {
                    break; // On sort de la boucle
                }

                printf("*"); // Imprime l'astérisque pour la séparation des facteurs
                number /= i; // Divise number par i pour continuer la factorisation
                i = 1; // Réinitialise i à 1 pour recommencer la boucle avec i = 2 au prochain incrément
            }
            i++; // Incrémente i pour tester le prochain potentiel facteur
        }
    }

    printf("\n"); // Imprime une nouvelle ligne à la fin
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

// Explications https://chatgpt.com/share/0eb901b3-df32-4b9e-a771-608ed02050ec

char *ft_strncpy(char *dest, const char *src, size_t n)
{
    size_t i;

    i = 0;
    while (src[i] && i < n)
    {
        dest[i] = src[i];
        i++;
    }
    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }
    return dest;
}

char **ft_split(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int wc = 0;

    // Compter le nombre de mots
    while (str[i])
    {
        // Ignorer les espaces, tabulations et retours à la ligne
        while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            i++;

        // Si on trouve un caractère non-espace, c'est un début de mot
        if (str[i])
            wc++;

        // Passer au mot suivant
        while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
            i++;
    }

    // Allouer de la mémoire pour les pointeurs de mots (wc + 1 pour le NULL final)
    char **out = (char **)malloc(sizeof(char *) * (wc + 1));
    i = 0;

    // Extraire chaque mot
    while (str[i])
    {
        // Ignorer les espaces, tabulations et retours à la ligne
        while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            i++;

        // Début du mot
        j = i;

        // Trouver la fin du mot
        while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
            i++;
        
        // Si on a trouvé un mot
        if (i > j)
        {
            // Allouer de la mémoire pour le mot
            out[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));

            // Copier le mot dans l'emplacement alloué
            ft_strncpy(out[k++], &str[j], i - j);
        }
    }
    // Terminer la liste des mots par un pointeur NULL
    out[k] = NULL;
    return (out);
}

// Explication https://chatgpt.com/share/03835be0-618b-4dc7-9180-a663d8b4a183

void rev_wstr(int argc, char *argv[])
{
    int start;
    int end;
    int i = 0;

    if (argc == 2)
    {
        // Calcul de la longueur de la chaîne
        while (argv[1][i] != '\0')
            i++;

        // Parcourir la chaîne à l'envers
        while (i >= 0)
        {
            // Ignorer les espaces et tabulations
            while (i >= 0 && (argv[1][i] == '\0' || argv[1][i] == ' ' || argv[1][i] == '\t'))
                i--;

            if (i < 0) 
                break;  // Sortir si début de chaîne atteint

            // Fin du mot
            end = i;

            // Trouver le début du mot
            while (i >= 0 && argv[1][i] != ' ' && argv[1][i] != '\t')
                i--;

            start = i + 1;

            // Afficher le mot
            int flag = start;
            while (start <= end)
            {
                write(1, &argv[1][start], 1);
                start++;
            }

            // Afficher un espace sauf après le dernier mot
            if (flag != 0)
            {
                write(1, " ", 1);
            }
        }
    }
    write(1, "\n", 1);
}

void write_word(char *start, char*end)
{
    while (start < end)
    {
        write(1, start, 1);
        start++;
    }
    
}

void rostring(int argc, char *argv[])
{
    char *str;
    char *first_word_start;
    char *first_word_end;

    if (argc > 1)
    {
        str = argv[1];
        while(*str == ' ' || *str == '\t')
            str++;
        first_word_start = str;
        while (*str && *str != ' ' || *str != '\t')
            str++;
        first_word_end = str;
        if (*str)
        {
            while (*str)
            {
                if (*str == ' ' || *str == '\t')
                {
                    while (*str == ' ' || *str == '\t')
                        str++;
                    if (*str)
                        write(1, " ", 1);
                }
                else
                {
                    write(1, str, 1);
                    str++;
                }
            }
            write(1, " ", 1);
        }
        write_word(first_word_start, first_word_end);
    }
    write(1, '\n', 1);
}

// Explication https://chatgpt.com/share/7e4dd72a-0843-4dbb-97f9-13ecc310d229

t_list *sort_list(t_list* lst, int (*cmp)(int, int)) 
{
    int swap;       // Variable pour échanger les valeurs
    t_list *tmp;    // Pointeur temporaire pour marquer le début de la liste

    tmp = lst;      // Initialiser tmp au début de la liste
    while (lst->next != NULL) 
    {  // Parcourir la liste jusqu'à l'avant-dernier élément
        // Comparer l'élément courant avec l'élément suivant en utilisant la fonction cmp
        if (((*cmp)(lst->data, lst->next->data)) == 0) 
        {
            // Si cmp retourne 0, échanger les valeurs des deux éléments
            swap = lst->data;
            lst->data = lst->next->data;
            lst->next->data = swap;
            lst = tmp;  // Revenir au début de la liste après un échange
        } 
        else 
        {
            // Si cmp ne retourne pas 0, avancer à l'élément suivant
            lst = lst->next;
        }
    }
    lst = tmp;  // Réinitialiser lst au début de la liste
    return (lst);  // Retourner le pointeur vers le début de la liste triée
}


#pragma endregion


int main (int argc, char *argv[])
{
    //do_op(argc, argv);
    //alpha_mirror(argc, argv);
    //camel_to_snake(argc, argv);
    //snake_to_camel(argc, argv);
    //ft_putnbr(255);
    //fizz_buzz();
    //repeat_alpha(argc, argv);
    //search_and_replace(argc, argv);
    //ulstr(argc, argv);

	/*char *s = "hello";
	const char *accept = "jfkhpell";
	printf("%zu\n", ft_strspn(s, accept));

    char *s2 = "hello";s
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

	/*t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);*/

    //printf("test itoa %s\n", ft_itoa(-485236));

}
