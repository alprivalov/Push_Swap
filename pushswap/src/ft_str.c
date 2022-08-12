#include "push_swap.h"

char	*ft_first_strjoin_push(char const *s1, char const *s2, t_push_swap *vars)
{
	char	*tab;
	int		i;
	int		j;
	int		len;

	if(ft_strlen(s2) == 0)
	{	
		write(2, "Error\n", 6);
		exit(0);
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	i = -1;
	j = 0;
	tab = malloc(sizeof(char) * len + 2);
	if (!tab)
		return (NULL);
	while (s1[++i])
		tab[i] = s1[i];
	tab[i] = ' ';
	i++;
	j = i - 1;
	i = -1;
	while (s2[++i])
	{
		tab[++j] = s2[i];
	}
	tab[j + 2] = 0;
	tab[j + 1] = ' ';
	return (tab);
}

char	*ft_strjoin_push(char *s1, char*s2, t_push_swap *vars)
{
	char	*tab;
	int		i;
	int		j;
	int		len;

	if (!s1 || !s2)
		error(vars);
	len = ft_strlen(s1) + ft_strlen(s2);
	i = -1;
	j = 0;
	tab = malloc(sizeof(char) * len + 2);
	if (!tab)
		return (NULL);
	while (s1[++i])
		tab[i] = s1[i];
	j = i - 1;
	i = -1;
	while (s2[++i])
	{
		tab[++j] = s2[i];
	}
	tab[j + 2] = 0;
	tab[j + 1] = ' ';
	free(s1);
	return (tab);
}

int     ft_len_str(int ac, char **av, t_push_swap *vars)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while (++i < ac)
    {
		if(ft_strlen(av[i]) <= 0)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		else
			len += ft_strlen(av[i]);
	}
    return (len); 
}

size_t	ft_strlcat_push(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = 0;
	if (size == 0 || dstlen > size)
		return (size + srclen);
	if (!*src)
		return (dstlen);
	while (src[i] && (i + dstlen) < size)
	{
		dst[i + dstlen] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}


void	ft_init_tab(int ac, t_push_swap *vars, char **av, t_data **list_a)
{
	int	i;
	int	number;
	char *str;
    int len;
	int j;
	int t;

	i = 0;
	t = 0;
	if (ac == 2)
		str = av[1];
	if (ac > 2)
	{
        len = ft_len_str(ac, av, vars);
        str = malloc(sizeof(char) * (len + ac));
        while(++i < ac)
		{
			j = -1;
			while (av[i][++j])
			{
				str[t] = av[i][j];
				t++;
			}
			str[t] = ' ';
			t++;
		}
    }
	ft_init_tab_ac_two(str, ac, vars, list_a);
	if(ac > 2)
	    free(str);
}