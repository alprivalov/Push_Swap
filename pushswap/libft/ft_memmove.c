/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:09:53 by alprival          #+#    #+#             */
/*   Updated: 2022/04/03 19:10:18 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	char			*tempdest;
	const char		*tempsrc;

	i = -1;
	tempdest = (char *)dest;
	tempsrc = (char *)src;
	if (!dest && !src)
		return (dest);
	if (tempdest < tempsrc)
		while (++i < n)
			tempdest[i] = tempsrc[i];
	else
		while (++i < n)
			tempdest[n - i - 1] = tempsrc[n - i - 1];
	return (dest);
}
