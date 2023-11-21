/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:54:46 by krocha-h          #+#    #+#             */
/*   Updated: 2023/11/17 15:54:31 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h>
#include <unistd.h>

static char	*copy_lst(t_list **lst)
{
	t_list	*node;
	char	*final_read;
	size_t	i;
	size_t	len;

	i = 0;
	node = *lst;
	while (node)
	{
		len = ft_strchr((char *)node->content, '\0') - (char *)node->content;
		i += len;
		node = node->next; 
	}
	final_read = malloc((i + 1) * sizeof(char));
	if (!final_read)
		return (NULL);
	node = *lst;
	i = 0;
	while (node)
	{
		len = ft_strchr((char *)node->content, '\0') - (char *)node->content;
		ft_strncpy(&final_read[i], (char *)node->content, len);
		i += len;
		node = node->next;
	}
	ft_lstclear(lst, free);
	final_read[i] = '\0';
	return (final_read);
}

/**
 * Consumes and returns the substring
*/
static char	*split_line(char **rest)
{
	char	*line;
	char	*new_rest;
	char	*nl;
	char	*end;

	nl = ft_strchr(*rest, '\n');
	end = ft_strchr(*rest, '\0');
	if (nl)
		line = ft_strndup(*rest, nl + 1 - *rest);
	else
		line = ft_strndup(*rest, end - *rest);
	if (nl && nl + 1 < end)
		new_rest = ft_strndup(nl + 1, end - nl + 1);
	else
		new_rest = NULL;
	free(*rest);
	*rest = new_rest;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	ssize_t		nbytes;
	t_list		*lst;
	t_list		*new_node;
	t_list		*last_node;
	static char	*rest;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (rest)
	{
		if (ft_strchr(rest, '\n'))
			return (split_line(&rest));
		new_node = ft_lstnew(rest);
		if (!new_node)
			return (NULL);
		lst = new_node;
		last_node = new_node;
	}
	else
		lst = NULL;
	nbytes = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	while (!ft_strchr(buffer, '\n') && nbytes > 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes > 0)
		{
			buffer[nbytes] = '\0';
			new_node = ft_lstnew(ft_strndup(buffer, nbytes));
			if (!new_node || !new_node->content)
				return (NULL);
			if (lst == NULL)
				lst = new_node;
			else
				last_node->next = new_node;
			last_node = new_node;
		}
	}
	if (lst == NULL)
		return (NULL);
	rest = copy_lst(&lst);
	if (!rest)
		return (NULL);
	return (split_line(&rest));
}
