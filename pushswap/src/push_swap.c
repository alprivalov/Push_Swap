/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:19:45 by alprival          #+#    #+#             */
/*   Updated: 2022/08/06 16:19:47 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	error(t_push_swap *vars)
{
	write(2, "Error\n", 6);
	ft_free_without_list(vars);
	exit(0);
}

void	ft_check_doublon(t_push_swap *vars, t_data **list_a)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < vars->len)
	{
		while (j < vars->len)
		{
			if (vars->tab_a[i] == vars->tab_a[j] && j != i)
				error(vars);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_init_list(t_push_swap *vars, t_data **list_a, t_data **list_b)
{
	int	i;

	i = 1;
	*list_a = ft_d_lstnew(vars->end_tab[0]);
	while (i < vars->len)
	{
		ft_d_lstadd_back(*list_a, ft_d_lstnew(vars->end_tab[i]));
		i++;
	}
	*list_b = NULL;
}

int	main(int ac, char **av)
{
	t_push_swap	vars;
	t_data		*list_a;
	t_data		*list_b;

	vars.len = ac - 1;
	if (ac < 2)
		return (0);
	else
		ft_init_tab(ac, &vars, av, &list_a);
	ft_better_tab(&vars);
	ft_init_list(&vars, &list_a, &list_b);
	if (vars.len == 2)
		ft_sort_two_a(&list_a);
	if (vars.len == 3)
		ft_sort_three(&list_a);
	if (vars.len > 3 && vars.len <= 5)
		ft_sort_five(&list_a, &vars, &list_b);
	if (vars.len > 5)
		ft_sort(&list_a, &list_b);
	ft_free(&vars, &list_a);
}
