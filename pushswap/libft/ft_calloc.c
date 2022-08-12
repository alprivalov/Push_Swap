/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:00:58 by alprival          #+#    #+#             */
/*   Updated: 2022/04/14 13:46:25 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;
	int		i;
	int		len;

	if (nmemb > 2147483647 || size > 2147483647 || size * nmemb > 2147483647)
		return (0);
	len = (nmemb * size);
	i = 0;
	tab = malloc(len);
	if (!tab)
		return (0);
	while (i < len)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
