/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:55:04 by krocha-h          #+#    #+#             */
/*   Updated: 2023/11/22 09:50:34 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	has_nl(t_list *lst)
{
	size_t	i;

	i = 0;
	while (i <= BUFFER_SIZE && lst && lst->content[i])
	{
		if (lst->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
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

size_t	get_line_len(t_list *lst)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		lst = lst->next;
	}
	return (len);
}

void	lst_remake(t_list **lst)
{
	t_list	*node;

	if (!lst)
		return ;
	while ((*lst)->next)
	{
		node = *lst;
		*lst = (*lst)->next;
		free(node->content);
		free(node);
	}
	if (!(*lst)->content[0])
	{
		free((*lst)->content);
		free(*lst);
		*lst = NULL;
	}
}
