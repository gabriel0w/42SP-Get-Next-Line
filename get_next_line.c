#include "get_next_line.h"

size_t ft_strichr(char *mem)
{
	size_t i;

	i = 0;
	while (mem[i] && mem[i] != '\n')
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	unsigned int i;

	i = 0;
	ptr = malloc(nmemb * size);
	if (ptr == 0)
		return (0);
	while (nmemb > i)
	{
		ptr[i] = 'g';
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char *find_line(char **buffer, char *read_result, int fd)
{
	int read_bytes;
	char *mem;

	mem = NULL;
	while (!(ft_strchr(read_result, '\n')))
	{
		read_bytes = read(fd, read_result, BUFFER_SIZE);
		if (read_bytes == 0)
		{
			if (!mem)
			{
				free(*buffer);
				return (NULL);
			}
			return (mem);
		}
		if (read_bytes == -1)
			return (NULL);
		read_result[read_bytes] = '\0';
		free(mem);
		mem = ft_strjoin(*buffer, read_result);
		free(*buffer);
		*buffer = ft_strdup(mem);
	}
	free(*buffer);
	*buffer = ft_substr(mem, ft_strichr(mem) + 1, ft_strlen(mem) - ft_strichr(mem));
	free(mem);
	return (ft_substr(mem, 0, ft_strichr(mem) + 1));
}

char	*get_next_line(int fd)
{
	static char *buffer;
	char *read_result;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (NULL);
	if (!buffer)
		buffer = NULL;
	read_result = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!read_result)
		return (0);
	line = find_line(&buffer, read_result, fd);
	free(read_result);
	return (line);
}
