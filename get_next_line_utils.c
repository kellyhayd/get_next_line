/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haydkelly <haydkelly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:55:04 by krocha-h          #+#    #+#             */
/*   Updated: 2023/11/21 18:25:19 by haydkelly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

int	is_nl(t_list *lst)
{
	int	i;

	while (lst)
	{
		i = 0;
		while (i <= BUFFER_SIZE && lst->content[i])
		{
			if (lst->content[i] == '\n')
				return (1);
			++i;
		}
		lst = lst->next;
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
	int		i;
	int		j;

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
				line[i++] = '\n';
				line[i] = '\0';
				return ;
			}
			line[i++] = lst->content[j++];
		}
		lst = lst->next;	
	}
	line[i] = '\0';
}

int	get_line_len(t_list *lst)
{
	int	i;
	int	len;

	if (!lst)
		return (0);
	len = 0;
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i] == '\n')
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		lst = lst->next;
	}	
	return (len);
}

void	ft_lst_remake(t_list **lst, t_list *rest, char *tmp)
{
	t_list	*buffer;

	if (!lst)
		return ;
	while (*lst)
	{
		buffer = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = buffer;
	}
	*lst = NULL;
	if (rest->content[0])
		*lst = rest;
	else
	{
		free(tmp);
		free(rest);
	}
}
