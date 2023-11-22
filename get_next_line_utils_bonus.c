/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haydkelly <haydkelly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:55:04 by krocha-h          #+#    #+#             */
/*   Updated: 2023/11/21 19:46:41 by haydkelly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

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

t_list  *ft_lstlast(t_list *lst)
{
    if (lst == NULL)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return(lst);
}

void	create_str(t_list *lst, char *line)
{
	size_t	i;
	size_t	j;

	if (!lst)
		return ;
	i = 0;
	while (lst)
	{
		j = 0;
		while (lst->content[j])
		{
			if (lst->content[j] == '\n')
			{
				line[i] = '\n';
				line[i + 1] = '\0';
				return ;
			}
			line[i] = lst->content[j];
			j++;
			i++;
		}
		lst = lst->next;	
	}
	line[i] = '\0';
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
