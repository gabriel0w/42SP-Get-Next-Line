#include "get_next_line.h"

size_t ft_strichr(char *mem)
{
	size_t i;

	if (!mem)
		return (0);
	i = 0;
	while (mem[i] && mem[i] != '\n')
		i++;
	return (i);
}

char *find_line(char **buffer, char *read_result, int fd, int read_bytes)
{
	char *mem;
	char *tmp;

	while (!(ft_strchr(*buffer, '\n')) && read_bytes != 0)
	{
		read_bytes = read(fd, read_result, BUFFER_SIZE);
		if (read_bytes <= 0)
			break;
		read_result[read_bytes] = '\0';
		mem = ft_strjoin(*buffer, read_result);
		free(*buffer);
		*buffer = ft_strdup(mem);
		free(mem);
	}
	if (!*buffer || !*buffer[0])
	{
		free(*buffer);
		return(NULL);
	}
	mem = ft_substr(*buffer, 0, ft_strichr(*buffer) + 1);
	tmp = ft_strdup(*buffer);
	free(*buffer);
	*buffer = ft_substr(tmp, ft_strichr(tmp) + 1, ft_strlen(tmp) - ft_strichr(tmp));
	free(tmp);
	return (mem);
}

char	*get_next_line(int fd)
{
	static char *buffer;
	char *read_result;
	char *line;
	int read_bytes;

	read_bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (NULL);
	if (!buffer)
		buffer = NULL;
	read_result = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!read_result)
		return (0);
	line = find_line(&buffer, read_result, fd, read_bytes);
	free(read_result);
	return (line);
}
