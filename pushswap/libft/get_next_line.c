/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:41:40 by alprival          #+#    #+#             */
/*   Updated: 2022/05/10 12:44:33 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenword(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

static char	*ft_join(int fd, char **save, char *buf, char *tmp)
{
	int		i;
	char	*line;
	int		len;

	i = 1;
	tmp = ft_get_strjoin(tmp, save[fd]);
	free(save[fd]);
	while (!ft_get_strchr(tmp, '\n') && i)
	{
		i = read(fd, buf, BUFFER_SIZE);
		buf[i] = '\0';
		tmp = ft_get_strjoin(tmp, buf);
	}
	len = ft_lenword(tmp);
	line = ft_get_substr(tmp, 0, len);
	save[fd] = ft_get_substr(tmp, len, ft_get_strlen(tmp) - len);
	free(buf);
	free(tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save[1024];
	char		*line;
	char		*buf;
	char		*tmp;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf || fd < 0 || read(fd, buf, 0) == -1 || BUFFER_SIZE < 1)
		return (free(buf), NULL);
	buf[BUFFER_SIZE] = '\0';
	tmp = ft_get_calloc(1, sizeof(char));
	if (!save[fd])
		save[fd] = ft_get_calloc(1, sizeof(char));
	line = ft_join(fd, save, buf, tmp);
	return (line);
}
