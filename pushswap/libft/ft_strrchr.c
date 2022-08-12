/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:10:45 by alprival          #+#    #+#             */
/*   Updated: 2022/04/03 19:11:54 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	int		temp;

	str = (char *)s;
	i = 0;
	temp = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char )c)
			temp = i;
		i++;
	}
	if ((unsigned char )c == 0)
		return (str + i);
	if (temp != 0 || str[0] == (unsigned char )c)
		return (str + temp);
	return (NULL);
}
