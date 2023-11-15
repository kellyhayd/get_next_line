/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:55:04 by krocha-h          #+#    #+#             */
/*   Updated: 2023/11/14 15:43:39 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* @brief Calculates the length of string
*
* @param String s
* @return Number of bytes in the string pointed to by s
*/
size_t	ft_strlen(const char *s)
{
	int	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

/* Allocate and returns a pointer to a null-terminated byte string,
which is a duplicate of the string pointed to by s.*/
char	*ft_strdup(const char *s)
{
	int		i;
	int		size;
	char	*dest;

	size = ft_strlen(s) + 1;
	dest = malloc(size * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

t_list  *ft_lstnew(void *content)
{
    t_list  *newlst;

    newlst = malloc(sizeof(t_list));
    if (!newlst)
        return (NULL);
    newlst->content = content;
    newlst->next = NULL;
    return (newlst);
}

/* Adds the node ’new’ at the end of the list */
void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *last;

    last = ft_lstlast(*lst);
    if (!last)
        *lst= new;
    else
        last->next = new;
}

/* Returns the last node of the list */
t_list  *ft_lstlast(t_list *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return(lst);
}

/* Deletes and frees the given node and every successor of that node, using the
function ’del’ and free. Finally, the pointer to the list must be set to NULL */
void    ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list  *tmp;

    while (*lst)
    {
        tmp = (*lst)->next;
        ft_lstdelone(*lst, del);
        *lst = tmp;
    }
    *lst = NULL;
}

/* Takes as a parameter a node and frees the memory of the node’s content using
the function ’del’ given as a parameter and free the node. The memory of
’next’ must not be freed */
void    ft_lstdelone(t_list *lst, void (*del)(void*))
{
    if (!lst)
        return;
    del(lst->content);
    free(lst);
}