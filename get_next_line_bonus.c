/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haydkelly <haydkelly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:00:16 by haydkelly         #+#    #+#             */
/*   Updated: 2023/11/21 22:55:05 by haydkelly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>

void	clean_lst(t_list **lst, t_list *last_node)
{
	size_t	i;
	size_t	j;

	if (!last_node)
		return ;
	j = 0;
	while (last_node->content[j] && last_node->content[j] != '\n')
		j++;
	if (last_node->content[j] == '\n')
		j++;
	i = 0;
	while (last_node->content[j])
	{	
		last_node->content[i] = last_node->content[j];
		i++;
		j++;
	}
	last_node->content[i] = '\0';
	lst_remake(lst);
}

char	*create_line(t_list *lst)
{
	char	*line;
	size_t	len;
	
	if (!lst)
		return (NULL);
	len = get_line_len(lst);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	create_str(lst, line);
	return (line);
}

int	lstadd_node(t_list **lst, t_list **last_node, char *buffer)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	if (!*last_node)
		*lst = new_node;
	else
		(*last_node)->next = new_node;
	new_node->content = buffer;
	new_node->next = NULL;
	(*last_node) = new_node;
	return (1);
}

int	create_lst(int fd, t_list **lst, t_list **last_node)
{
	char	*buffer;
	int		nbytes;
	
	while (!has_nl(*last_node))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (0);
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes <= 0)
		{
			free(buffer);
			return (nbytes == 0);
		}
		buffer[nbytes] = '\0';
		if (!lstadd_node(lst, last_node, buffer))
		{
			free(buffer);
			return (0);
		}
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static t_files	*active_fds;
	t_files			*tmp;
	t_list			*last_node;
	char			*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = active_fds;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (!tmp)
	{
		tmp = malloc(sizeof(t_files));
		if (!tmp)
			return (NULL);
		tmp->fd = fd;
		tmp->lst = NULL;
		tmp->next = active_fds;
		active_fds = tmp;
	}
	last_node = ft_lstlast(tmp->lst);
	create_lst(fd, &tmp->lst, &last_node);
	new_line = create_line(tmp->lst);
	clean_lst(&tmp->lst, last_node);
	return (new_line);
}