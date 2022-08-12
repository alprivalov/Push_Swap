/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:05:19 by alprival          #+#    #+#             */
/*   Updated: 2022/08/06 16:05:21 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*ft_d_lstnew(int content)
{
	t_data	*new;

	new = malloc(sizeof(t_data));
	if (!new)
		return (NULL);
	new -> value = content;
	new -> next = NULL;
	new -> preview = NULL;
	return (new);
}

t_data	*ft_d_lstlast(t_data *lst)
{
	if (lst)
	{
		while (lst -> next)
			lst = lst -> next;
	}
	return (lst);
}

void	ft_d_lstadd_back(t_data *list, t_data *new)
{
	t_data	*temp;

	if (list)
	{
		temp = ft_d_lstlast(list);
		temp -> next = new;
		new -> preview = temp;
	}
}

int	ft_atoi_push(const char *nptr, t_push_swap *vars, t_data **list_a)
{
	int			i;
	long int	result;
	int			neg;
	int			flag;

	neg = 1;
	i = 0;
	flag = 0;
	result = 0;
	while ((nptr[i] == ' ') || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nptr[i])
	{
		if ((nptr[i] < '0' || nptr[i] > '9') && nptr[i] != ' ')
			error(vars);
		else if (nptr[i] >= '0' && nptr[i] <= '9')
		{
			result = result * 10;
			result = result + nptr[i] - '0';
			flag = 1;
			if (result > INT_MAX || result < INT_MIN)
				error(vars);
		}
		i++;
	}
	if (flag == 1)
		return (result * neg);
	else
		error(vars);
}
