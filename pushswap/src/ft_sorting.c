/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:31:42 by alprival          #+#    #+#             */
/*   Updated: 2022/08/06 16:31:43 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_list_sorted(t_data **list_a)
{
	int	list;

	list = 0;
	if ((*list_a))
	{
		while ((*list_a)->next)
		{
			if ((*list_a)->value > (*list_a)->next->value)
				list = 1;
			(*list_a) = (*list_a)->next;
		}
	}
	while ((*list_a)->preview)
			(*list_a) = (*list_a)->preview;
	if (list == 0)
		return (1);
	else
		return (0);
}

int	len_list(t_data **list_a)
{
	t_data	*tmp;
	int		i;

	tmp = (*list_a);
	i = 0;
	if ((tmp))
	{
		while ((tmp))
		{
			(tmp) = (tmp)->next;
			i++;
		}
	}
	return (i);
}

void	ft_sort(t_data **list_a, t_data **list_b)
{
	int	i;
	int	j;
	int	num;
	int	size;

	size = len_list(list_a);
	j = 0;
	i = 0;
	while (i < 32)
	{
		if (ft_list_sorted(list_a))
			return ;
		while (j < size)
		{
			num = (*list_a)->value;
			if ((num >> i) & 1 == 1)
				ft_ra(list_a);
			else
				ft_pb(list_a, list_b);
			j++;
		}
		while ((*list_b))
			ft_pa(list_a, list_b);
		i++;
		j = 0;
	}
}

void	ft_sort_two_b(t_data **list_b)
{
	if (!ft_list_sorted(list_b))
		ft_sb(list_b);
}

void	ft_sort_two_a(t_data **list_a)
{
	if (!ft_list_sorted(list_a))
		ft_sa(list_a);
}

void	ft_sort_three(t_data **list_a)
{
	while (!ft_list_sorted(list_a))
	{
		if ((*list_a)->value > (*list_a)->next->value
			&& (*list_a)->value > (*list_a)->next->next->value)
			ft_ra(list_a);
		if ((*list_a)->value > (*list_a)->next->value
			&& (*list_a)->value < (*list_a)->next->next->value)
			ft_sa(list_a);
		if ((*list_a)->next->value > (*list_a)->next->next->value)
			ft_ra(list_a);
	}
}

void	ft_sort_five(t_data **list_a, t_push_swap *vars, t_data **list_b)
{
	if (!ft_list_sorted(list_a))
	{
		while ((*list_a)->value != 0 && (*list_a)->value != vars->len - 1)
			ft_ra(list_a);
		ft_pb(list_a, list_b);
		while ((*list_a)->value != 0 && (*list_a)->value != vars->len - 1)
			ft_ra(list_a);
		ft_pb(list_a, list_b);
		if (vars->len == 5)
			ft_sort_three(list_a);
		if (vars->len == 4)
			ft_sort_two_a(list_a);
		ft_sort_two_b(list_b);
		ft_pa(list_a, list_b);
		ft_pa(list_a, list_b);
		ft_ra(list_a);
	}
}
