/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:54:46 by krocha-h          #+#    #+#             */
/*   Updated: 2023/11/14 17:57:50 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		buffer[BUFFER_SIZE];
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, buffer, 1) < 1))
		return (0);
	if (!tmp)
		return (0);
	while (!ft_strchr(tmp, '\n'))
	{
		while (read(fd, buffer, 1) != '\0')
		{
			if (buffer == '\n')
				break;
			tmp[i] = &buffer;
			i++;
		}
		// free(buffer);
	}
	*tmp = '\0';
	printf("%s\n", tmp);
	return (tmp);
}


size_t	ft_strlen(const char *s)
{
	int	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		size;
	char	*dest;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest = malloc (size * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

int main () {
	int	fd = open("texto_exemplo", O_RDONLY);

	printf("%s\n", get_next_line(fd));
	return (0);
}
