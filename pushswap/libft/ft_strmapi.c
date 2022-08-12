/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:45:33 by alprival          #+#    #+#             */
/*   Updated: 2022/04/14 13:45:36 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	int		len;
	char	*tab;

	if (!s)
		return (0);
	len = ft_strlen(s);
	index = 0;
	tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (0);
	while (s[index])
	{
		tab[index] = f(index, s[index]);
		index++;
	}
	tab[index] = '\0';
	return (tab);
}
