/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncsomori <ncsomori@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:38:43 by ncsomori          #+#    #+#             */
/*   Updated: 2021/12/16 10:38:48 by ncsomori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_linecat(char **line, char **s)
{
	size_t	i;
	char	*temp;

	i = 0;
	if (!(*s))
		return (0);
	while ((*s)[i] != '\n' && (*s)[i] != '\0')
		i++;
	if ((*s)[i] == '\n')
	{
		*line = ft_strsub(*s, 0, i);
		temp = ft_strdup(&((*s)[i + 1]));
		free(*s);
		*s = temp;
		if ((*s)[0] == '\0')
			ft_strdel(s);
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
	return (1);
}

static int	ft_getline(char **s, char *buff, const int fd, int ret)
{
	char	*temp;

	while (ret > 0)
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret <= 0)
			return (ret);
		buff[ret] = '\0';
		if (!s[fd])
			s[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = temp;
		}
		if (ft_strchr(s[fd], '\n'))
			return (ret);
	}
	return (ret);
}

int	get_next_line(const int fd, char **line)
{
	static char	*save[MAX_FD];
	char		*buff;
	int			ret;

	if (fd > MAX_FD || fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	buff = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buff)
		return (-1);
	ret = 1;
	ret = ft_getline(save, buff, fd, ret);
	free(buff);
	if (ret < 0)
		return (-1);
	if (ret == 0 && !save[fd])
		return (0);
	return (ft_linecat(line, &save[fd]));
}
