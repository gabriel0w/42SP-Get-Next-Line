/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbelo-so <gbelo-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 22:46:01 by gbelo-so          #+#    #+#             */
/*   Updated: 2021/11/14 22:46:02 by gbelo-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	string_len;
	size_t	i;
	char	*substr;

	if (s == NULL)
		return (NULL);
	string_len = ft_strlen(s);
	if (start > string_len)
		return (ft_strdup(""));
	if (start + len > string_len)
		len = string_len - start;
	substr = malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

size_t	ft_strlen(const char *string)
{
	size_t	i;

	if (!string)
		return (0);
	if (!string[0])
		return (0);
	i = 0;
	while (string[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dst;

	if (!src || !src[0])
		return (NULL);
	dst = malloc(ft_strlen(src) + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	str = (char *)malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
			str[i++] = s1[j++];
	}
	j = 0;
	if (s2)
	{
		while (s2[j])
			str[i++] = s2[j++];
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count])
	{
		if (s[count] == (unsigned char)c)
			return ((char *)s + count);
		count++;
	}
	if (c == '\0')
		return ((char *)s + (count));
	return (NULL);
}
