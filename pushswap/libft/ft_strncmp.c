/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 21:09:20 by alprival          #+#    #+#             */
/*   Updated: 2022/04/12 21:09:40 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*strs1;
	unsigned char	*strs2;

	strs1 = (unsigned char *)s1;
	strs2 = (unsigned char *)s2;
	i = 0;
	while ((strs1[i] || strs2[i]) && (i < n))
	{
		if (strs1[i] - strs2[i] != 0)
			return (strs1[i] - strs2[i]);
		i++;
	}
	return (0);
}
