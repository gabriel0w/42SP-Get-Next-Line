/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbelo-so <gbelo-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 22:45:25 by gbelo-so          #+#    #+#             */
/*   Updated: 2021/11/14 22:45:26 by gbelo-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_ichr(char *mem)
{
	size_t	i;

	if (!mem)
		return (0);
	i = 0;
	while (mem[i] && mem[i] != '\n')
		i++;
	return (i);
}

char	*find_line(char **buf, char *read_result, int fd, int read_bytes)
{
	char	*mem;
	char	*tmp;

	while (!(ft_strchr(*buf, '\n')) && read_bytes != 0)
	{
		read_bytes = read(fd, read_result, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		read_result[read_bytes] = '\0';
		mem = ft_strjoin(*buf, read_result);
		free(*buf);
		*buf = ft_strdup(mem);
		free(mem);
	}
	if (!*buf || !*buf[0])
	{
		free(*buf);
		return (NULL);
	}
	mem = ft_substr(*buf, 0, ft_ichr(*buf) + 1);
	tmp = ft_strdup(*buf);
	free(*buf);
	*buf = ft_substr(tmp, ft_ichr(tmp) + 1, ft_strlen(tmp) - ft_ichr(tmp));
	free(tmp);
	return (mem);
}

char	*get_next_line(int fd)
{
	static char	*buf[256];
	char		*read_result;
	char		*line;
	int			read_bytes;

	read_bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (NULL);
	read_result = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!read_result)
		return (NULL);
	line = find_line(&buf[fd], read_result, fd, read_bytes);
	free(read_result);
	return (line);
}
