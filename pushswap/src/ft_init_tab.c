/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:31:51 by alprival          #+#    #+#             */
/*   Updated: 2022/08/06 16:31:52 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_tab_init(char *av)
{
	write(2, "Error\n", 6);
	free(av);
	exit(0);
}

void	ft_len_tab(char *av, t_push_swap *vars, t_data **list_a)
{
	int	i;
	int	flag;

	i = 0;
	while (av[i])
	{
		flag = 0;
		if (av[i] >= '0' && av[i] <= '9' || av[i] == '-' )
		{
			while (av[i] != ' ' && av[i])
			{
				if (av[i] == '-' && flag == 0 || (av[i] >= '0' && av[i] <= '9'))
				{
					flag++;
					i++;
				}
				else if (av[i] < '0' || av[i] > '9')
					ft_error_tab_init(av);
				else
					i++;
			}
			vars->len++;
		}
		i++;
	}
}

void	ft_write_tab(char *av, t_push_swap *vars, t_data **list_a)
{
	int	i;
	int	neg;
	int	result;
	int	j;

	j = 0;
	i = 0;
	while (av[i])
	{
		result = 0;
		neg = 1;
		if (av[i] >= '0' && av[i] <= '9' || av[i] == '-')
		{
			if (av[i] == '-')
			{
				neg *= -1;
				i++;
			}
			while (av[i] >= '0' && av[i] <= '9' && av[i])
			{
				if (result > INT_MAX || result < INT_MIN)
					error(vars);
				result *= 10;
				result += (av[i] - '0');
				i++;
			}
			vars->tab_a[j] = result * neg;
			j++;
		}
		i++;
	}
}

void	ft_init_tab_ac_two(char *str, int ac, t_push_swap *vars, t_data **list_a)
{
	vars->len = 0;
	if (!(str[0] >= '0' && str[0] <= '9' || str[0] == '-' || str[0] == ' '))
		ft_error_tab_init(str);
	ft_len_tab(str, vars, list_a);
	vars->tab_a = malloc(sizeof(int ) * vars->len + 1);
	ft_write_tab(str, vars, list_a);
	ft_check_doublon(vars, list_a);
}
