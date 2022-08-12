/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:10:42 by alprival          #+#    #+#             */
/*   Updated: 2022/08/06 16:10:44 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_data **list_a)
{
	int	swap;

	if (*list_a && (*list_a)->next)
	{
		swap = (*list_a)->value;
		(*list_a)->value = (*list_a)->next->value;
		(*list_a)->next->value = swap;
	}
	printf("sa\n");
}

void	ft_sb(t_data **list_b)
{
	int	swap;

	if (*list_b && (*list_b)->next)
	{
		swap = (*list_b)->value;
		(*list_b)->value = (*list_b)->next->value;
		(*list_b)->next->value = swap;
	}
	printf("sb\n");
}

void	ft_ss(t_data **list_b, t_data **list_a)
{
	ft_sa(list_a);
	ft_sb(list_b);
}

void	ft_pa(t_data **list_a, t_data **list_b)
{
	if (*list_a && *list_b)
	{
		(*list_a)->preview = *list_b;
		*list_b = (*list_b)->next;
		if ((*list_b) != NULL)
			(*list_b)->preview = NULL;
		(*list_a)->preview->next = *list_a;
		(*list_a) = (*list_a)->preview;
	}
	else if (*list_b)
	{
		*list_a = *list_b;
		*list_b = (*list_b)->next;
		(*list_a)->next = NULL;
		if ((*list_b) != NULL)
			(*list_b)->preview = NULL;
	}
	printf("pa\n");
}

void	ft_pb(t_data **list_a, t_data **list_b)
{
	if (*list_b && *list_a)
	{
		(*list_b)->preview = *list_a;
		*list_a = (*list_a)->next;
		if ((*list_a) != NULL)
			(*list_a)->preview = NULL;
		(*list_b)->preview->next = *list_b;
		(*list_b) = (*list_b)->preview;
	}
	else if (*list_a)
	{
		*list_b = *list_a;
		*list_a = (*list_a)->next;
		(*list_b)->next = NULL;
		if ((*list_a) != NULL)
			(*list_a)->preview = NULL;
	}
	printf("pb\n");
}

void	ft_ra(t_data **list_a)
{
	t_data	*tmp;

	if ((*list_a) && (*list_a)->next)
	{
		tmp = (*list_a);
		(*list_a) = (*list_a)->next;
		(*list_a)->preview = NULL;
		while ((*list_a)->next)
			(*list_a) = (*list_a)->next;
		(*list_a)->next = tmp;
		(*list_a)->next->next = NULL;
		(*list_a)->next->preview = (*list_a);
		while ((*list_a)->preview)
			(*list_a) = (*list_a)->preview;
		if ((*list_a)->preview != NULL)
			(*list_a) = (*list_a)->preview;
	}
	printf("ra\n");
}

void	ft_rb(t_data **list_b)
{
	t_data	*tmp;

	if ((*list_b) && (*list_b)->next)
	{	
		tmp = (*list_b);
		(*list_b) = (*list_b)->next;
		(*list_b)->preview = NULL;
		while ((*list_b)->next)
			(*list_b) = (*list_b)->next;
		(*list_b)->next = tmp;
		(*list_b)->next->next = NULL;
		(*list_b)->next->preview = (*list_b);
	}
	while ((*list_b)->preview)
		(*list_b) = (*list_b)->preview;
	if ((*list_b)->preview != NULL)
		(*list_b) = (*list_b)->preview;
	printf("rb\n");
}

void	ft_rr(t_data **list_a, t_data **list_b)
{
	ft_ra(list_a);
	ft_rb(list_b);
}

void	ft_rra(t_data **list_a)
{
	t_data	*tmp;

	if ((*list_a) && (*list_a)->next)
	{
		while ((*list_a)->next)
			(*list_a) = (*list_a)->next;
		tmp = (*list_a);
		(*list_a) = (*list_a)->preview;
		(*list_a)->next = NULL;
		while ((*list_a)->preview)
			(*list_a) = (*list_a)->preview;
		(*list_a)->preview = tmp;
		(*list_a)->preview->preview = NULL;
		(*list_a)->preview->next = (*list_a);
		if ((*list_a)->preview != NULL)
			(*list_a) = (*list_a)->preview;
	}
	printf("rra\n");
}

void	ft_rrb(t_data **list_b)
{
	t_data	*tmp;

	if ((*list_b) && (*list_b)->next)
	{
		while ((*list_b)->next)
			(*list_b) = (*list_b)->next;
		tmp = (*list_b);
		(*list_b) = (*list_b)->preview;
		(*list_b)->next = NULL;
		while ((*list_b)->preview)
			(*list_b) = (*list_b)->preview;
		(*list_b)->preview = tmp;
		(*list_b)->preview->preview = NULL;
		(*list_b)->preview->next = (*list_b);
		if ((*list_b)->preview != NULL)
			(*list_b) = (*list_b)->preview;
	}
	printf("rrb\n");
}

void	ft_rrr(t_data **list_a, t_data **list_b)
{
	ft_rra(list_a);
	ft_rrb(list_b);
}
