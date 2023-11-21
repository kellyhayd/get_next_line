/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haydkelly <haydkelly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:00:16 by haydkelly         #+#    #+#             */
/*   Updated: 2023/11/21 18:28:14 by haydkelly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

void	clean_lst(t_list **lst)
{
	t_list	*rest;
	t_list	*last_node;
	char	*tmp;
	int		i;
	int		j;

	tmp = malloc(BUFFER_SIZE + 1);
	rest = malloc(sizeof(t_list));
	if (!tmp || !rest)
		return ;
	last_node = ft_lstlast(*lst);
	i = 0;
	j = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		++i;
	while (last_node->content[i] && last_node->content[++i])
		tmp[j++] = last_node->content[i];
	tmp[j] = '\0';
	rest->content = tmp;
	rest->next = NULL;
	ft_lst_remake(lst, rest, tmp);
}

char	*create_line(t_list *lst)
{
	char	*line;
	int		len;
	
	if (!lst)
		return (NULL);
	len = get_line_len(lst);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	create_str(lst, line);
	return (line);
}

void	lstadd_node(t_list **lst, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_lstlast(*lst);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	if (!last_node)
		*lst = new_node;
	else
		last_node->next = new_node;
	new_node->content = buf;
	new_node->next = NULL;
}

void	create_lst(t_list **lst, int fd)
{
	char	*buffer;
	int		nbytes;

	while (!is_nl(*lst))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[nbytes] = '\0';
		lstadd_node(lst, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	create_lst(&lst, fd);
	if (!lst)
		return (NULL);
	new_line = create_line(lst);
	clean_lst(&lst);
	return (new_line);
}