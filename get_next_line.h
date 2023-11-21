/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haydkelly <haydkelly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:55:14 by krocha-h          #+#    #+#             */
/*   Updated: 2023/11/21 16:34:57 by haydkelly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		is_nl(t_list *lst);
int		get_line_len(t_list *list);
t_list  *ft_lstlast(t_list *lst);
void	lstadd_node(t_list **list, char *buf);
void	clean_lst(t_list **lst);
void	create_str(t_list *lst, char *line);
char	*create_line(t_list *lst);
void	create_lst(t_list **lst, int fd);
void	ft_lst_remake(t_list **lst, t_list *rest, char *tmp);

#endif
