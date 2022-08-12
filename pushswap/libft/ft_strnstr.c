/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:14:33 by alprival          #+#    #+#             */
/*   Updated: 2022/04/03 19:17:18 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*strs1;
	char	*strs2;

	strs1 = (char *)s1;
	strs2 = (char *)s2;
	i = -1;
	j = 0;
	if (strs2[j] == '\0')
		return (strs1);
	while (strs1[++i] && i < n)
	{
		if (strs1[i] == strs2[j])
		{
			while (strs1[i + j] == strs2[j]
				&& j < ft_strlen(strs2) && i + j < n)
				j++;
			if (j == ft_strlen(strs2))
				return (&strs1[i]);
			else
				j = 0;
		}
	}
	return (NULL);
}
