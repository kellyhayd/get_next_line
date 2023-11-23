/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haydkelly <haydkelly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:55:14 by krocha-h          #+#    #+#             */
/*   Updated: 2023/11/23 09:01:04 by haydkelly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

/*
 * @brief Reads `BUFFER_SIZE` characters at time, returning the next
 * line in file. The characters that was readen and exceed the line.
 * are storaged in a static variable.
 *
 * @param fd File Descriptor
 * @return The `next line` of the file.
 */
char	*get_next_line(int fd);

/*
 * @brief Allocates and creates the string that contains
 * the next line of the fd.
 *
 *  * Call `get_line_len` to calculate the length of line to allocate
 * and `create_str` to copy every character from the nodes.
 *
 * @param *lst The list created of the reading of the file
 * @return The next `line` of the file.
 * @return `NULL` in cases of list is NULL or allocation
 * of line fails.
 */
char	*create_line(t_list *lst);

/*
 * @brief Checks if there is a `\ n` in the list,
 * indicating the end of line.
 *
 * @param *lst The list of characters read
 * @return `True` or `False`
 */
int		has_nl(t_list *lst);

/*
 * @brief Reads the `fd` and allocates `buffer` in a new node of a linked list.
 *
 * @param fd file descriptor
 * @param **lst  a pointer to the list of nodes
 * @param **last_node - a pointer to the last node of the list
 * @return `True` or `False` to the success of the creation of the list.
 * It can fails if allocation of buffer or adding a new node fails.
 */
int		create_lst(int fd, t_list **lst, t_list **last_node);

/*
 * @brief Adds a new node at the end of the linked list with the
 * content of buffer from the last read.
 *
 * @param **lst The linked list with the results of reading
 * @param **last_node The last node of the linked list
 * @param *buffer The content storage from the last reading
 * @return `True` or `False` indicating the success of the function
 */
int		lstadd_node(t_list **lst, t_list **last_node, char *buffer);

/*
 * @brief It will `free` every node of the linked list, except the last one,
 * that could contains characters of the next line.
 *
 * @param **lst The linked list that contains the result of the reading
 */
void	lst_remake(t_list **lst);

/*
 * @brief Copies the characters of each node of the linked list
 * until it finds the `\ n` indicating the end of line.
 * It tests if list is not NULL and guarantee that string will
 * be terminated by a `\0`.
 *
 * @param *lst The linked list that storagem the content read
 * @param *line The char that will storage the characters
 */
void	create_str(t_list *lst, char *line);

/*
 * @brief Searches if there is anything after the `\ n` and storage it in
 * a node that will become the only one of static linked list.
 * After coping the remmant content, it calls `lst_remake` to
 * clean the leftover nodes.
 *
 * @param **lst The linked list with the content of the reading
 * @param *last_node The last node of the list
 */
void	clean_lst(t_list **lst, t_list *last_node);

/*
 * @brief Calculates the length of the string that will contains
 * the nest line of the file.
 *
 * @param *list The list with te content of the reading
 * @return The `size` of the string that will be created.
 */
size_t	get_line_len(t_list *list);

/*
 * @brief Finds the last node of the linked list
 *
 * @param *lst The linked list with the content of the reading
 * @return A pointer to the last node of the list.
 */
t_list	*ft_lstlast(t_list *lst);

#endif
