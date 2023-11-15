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


// size_t	ft_strlen(const char *s)
// {
// 	int	size;

// 	size = 0;
// 	while (s[size] != '\0')
// 		size++;
// 	return (size);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	int		i;
// 	int		j;
// 	int		size;
// 	char	*dest;

// 	if (s1 == NULL || s2 == NULL)
// 		return (NULL);
// 	size = ft_strlen(s1) + ft_strlen(s2) + 1;
// 	dest = malloc (size * sizeof(char));
// 	if (dest == NULL)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s1[i])
// 	{
// 		dest[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j])
// 	{
// 		dest[i + j] = s2[j];
// 		j++;
// 	}
// 	dest[i + j] = 0;
// 	return (dest);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	while (*s)
// 	{
// 		if (*s == (unsigned char)c)
// 			return ((char *)s);
// 		s++;
// 	}
// 	if (c == 0)
// 		return ((char *)s);
// 	return (NULL);
// }

char	*get_next_line(int fd)
{
	char		*line;
	char		*tmp;
	static char	buffer[BUFFER_SIZE + 1];
	size_t		i;
	size_t		j;
	ssize_t		nbytes;
	size_t		len;
	int			is_eol;
	t_list		*lst;
	t_list		*new_node;
	t_list		*last_node;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lst = NULL;
	is_eol = 0;
	nbytes = 1;
	len = 0;
	while (!is_eol && nbytes > 0)
	{
		i = 0;
		while (i != BUFFER_SIZE && !is_eol && (nbytes = read(fd, &buffer[i], 1)) > 0)
		{
			if (buffer[i] == '\n')
				is_eol = 1;
			i++;
		}
		len += i;
		if (i > 0)
		{
			buffer[i] = '\0';
			tmp = ft_strdup(buffer);
			new_node = ft_lstnew((void *)tmp);
			if (lst == NULL)
				lst = new_node;
			else
				last_node->next = new_node;
			last_node = new_node;
		}
	}
	if (nbytes < 0)
	{
		if (lst != NULL)
			ft_lstclear(&lst, free);
		return (NULL);
	}
	if (lst == NULL)
		return (NULL);
	line = (char *)malloc(len + 1);
	new_node = lst;
	i = 0;
	while (new_node)
	{
		tmp = (char *)new_node->content;
		j = 0;
		while (tmp[j] != '\0')
			line[i++] = tmp[j++];
		new_node = new_node->next;
	}
	line[i] = '\0';
	ft_lstclear(&lst, free);
	return (line);
}

// int main () {
// 	int	fd = open("gnlTester/files/empty", O_RDONLY);

// 	get_next_line(fd);
// 	return (0);
// }
