/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:31:26 by alprival          #+#    #+#             */
/*   Updated: 2022/08/06 16:31:27 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_list(t_data **list_a)
{
	t_data	*tmp;

	if ((*list_a))
	{
		while ((*list_a)->next)
		{
			tmp = (*list_a);
			(*list_a) = (*list_a)->next;
			free(tmp);
		}
	}
	free((*list_a));
}

void	ft_free_without_list(t_push_swap *vars)
{
	int	i;

	i = 0;
	if(vars->end_tab)
		free(vars->end_tab);
	if(vars->tab_a)
		free(vars->tab_a);
}

void	ft_free(t_push_swap *vars, t_data **list_a)
{
	int	i;

	i = 0;
	if(vars->end_tab)
		free(vars->end_tab);
	if(vars->tab_a)
		free(vars->tab_a);
	if((*list_a))
		ft_free_list(list_a);
}
