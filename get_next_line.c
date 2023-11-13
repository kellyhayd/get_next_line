/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:54:46 by krocha-h          #+#    #+#             */
/*   Updated: 2023/11/13 14:05:39 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		i;
	char	c;
	char	buffer[BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	i = 0;
	while (buffer[i] != '\n')
	{
		while (read(fd, &c, 1) != '\n')
		{
			if (!c)
				return (0);
			buffer[i] = c;
			i++;
		}
		i++;
	}
	return (buffer);
}

int	read_line;
char	*buffer;

buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
if (!buffer)
	return (0);
read_line = read(fd, buffer, BUFFER_SIZE);
if (read_line < 1)
	return (0);
buffer[read_line] = '\0';

