/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_better_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:07:33 by alprival          #+#    #+#             */
/*   Updated: 2022/08/06 16:07:35 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_new_tab(t_push_swap *vars)
{
	int	*tab;
	int	i;

	i = 0;
	vars->end_tab = malloc(sizeof(int) * vars->len + 1);
	tab = malloc(sizeof(int) * vars->len + 1);
	while (i < vars->len)
	{
		tab[i] = vars->tab_a[i];
		i++;
	}
	return (tab);
}

void	ft_better_tab(t_push_swap *vars)
{
	int	*tab;
	int	i;
	int	j;
	int	t;
	int	swap;

	i = 0;
	tab = ft_new_tab(vars);
	while (i < vars->len && i + 1 < vars->len)
	{
		if (tab[i] > tab[i + 1])
		{
			swap = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
	i = 0;
	i = 0;
	j = 0;
	while (i < vars->len)
	{
		while (j < vars->len)
		{
			if (vars->tab_a[i] == tab[j])
				vars->end_tab[i] = j;
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	free(tab);
}
