/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:12:38 by alprival          #+#    #+#             */
/*   Updated: 2022/04/14 13:30:45 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*strs1;
	unsigned char	*strs2;

	strs1 = (unsigned char *)s1;
	strs2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (strs1[i] - strs2[i] != 0)
			return (strs1[i] - strs2[i]);
		i++;
	}
	return (0);
}
