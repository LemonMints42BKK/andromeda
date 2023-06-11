/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 09:45:58 by kchatvet          #+#    #+#             */
/*   Updated: 2022/07/14 13:36:25 by kchatvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_nl(char *buff)
{
	if (!buff)
		return (0);
	while (*buff != '\0')
	{
		if (*buff == '\n')
			return (1);
		buff++;
	}
	return (0);
}

char	*read_gnl(char *str)
{
	char	*gnl;
	int		i;

	if (str[0] == '\0')
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	gnl = (char *)malloc((i + 2) * sizeof(char));
	if (!gnl)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		gnl[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		gnl[i++] = '\n';
	gnl[i] = '\0';
	return (gnl);
}

char	*still_data(char *str)
{
	char	*left_data;
	int		j;
	int		k;

	if (!str)
		return (NULL);
	j = 0;
	while (str[j] != '\0' && str[j] != '\n')
		j++;
	if (str[j] == '\0')
	{
		free(str);
		return (NULL);
	}
	left_data = (char *)malloc((lenstr(str) - j + 1) * sizeof(char));
	if (!left_data)
		return (NULL);
	j++;
	k = 0;
	while (str[j] != '\0')
		left_data[k++] = str[j++];
	left_data[k] = '\0';
	free(str);
	return (left_data);
}

char	*get_next_line(int fd)
{
	static char	*data[10000];
	char		*read_line;
	int			gnl_size;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 10000)
		return (NULL);
	read_line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!read_line)
		return (NULL);
	gnl_size = BUFFER_SIZE;
	while (gnl_size != 0 && !check_nl(data[fd]))
	{
		gnl_size = read(fd, read_line, BUFFER_SIZE);
		if (gnl_size == -1)
		{
			free(read_line);
			return (NULL);
		}
		read_line[gnl_size] = '\0';
		data[fd] = joinstr(data[fd], read_line);
	}
	free(read_line);
	read_line = read_gnl(data[fd]);
	data[fd] = still_data(data[fd]);
	return (read_line);
}
