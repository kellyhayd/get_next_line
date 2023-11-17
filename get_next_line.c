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

static char	*copy_lst(t_list *lst, t_list *new_node, size_t len)
{
	char	*tmp;
	char	*final_read;
	int		i;
	int		j;

	final_read = malloc((len + 1) * sizeof(char));
	if (!final_read)
		return (NULL);
	tmp = NULL;
	i = 0;
	while (new_node)
	{
		tmp = (char *)new_node->content;
		j = 0;
		while (tmp[j] != '\0')
		{
			final_read[i] = tmp[j];
			i++;
			j++;
		}
		new_node = new_node->next;
	}
	ft_lstclear(&lst, free);
	final_read[i] = '\0';
	return (final_read);
}

static char	*create_line(char *final_read)
{
	char	*line;
	int		len_line;
	int		i;

	len_line = 0;
	while (final_read[len_line] != '\n' && final_read[len_line] != '\0')
		len_line++;
	if (final_read[len_line] == '\n')
		len_line++;
	line = malloc((len_line + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (final_read[i] != '\n' && final_read[i] != '\0')
	{
		line[i] = final_read[i];
		i++;
	}
	if (final_read[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*create_rest(char *final_read, size_t len)
{
	char	*rest;
	size_t		i;
	size_t		j;

	i = 0;
	rest = NULL;
	while (final_read[i] != '\n' && final_read[i] != '\0')
		i++;
	if (final_read[i] == '\n')
		i++;
	if (len > i)
	{
		rest = malloc((len - i) * sizeof(char));
		if (!rest)
			return (NULL);
	}
	else
		return (NULL);
	j = 0;
	while (final_read[i] != '\0')
		rest[j++] = final_read[i++];
	rest[j] =  '\0';
	free(final_read);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*tmp;
	char	buffer[BUFFER_SIZE + 1];
	size_t		i;
	ssize_t		nbytes;
	size_t		len;
	int			is_eol;
	t_list		*lst;
	t_list		*new_node;
	t_list		*last_node;
	static char		*rest;
	char		*final_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	if (rest != (void *)0)
	{
		len = ft_strlen(rest);
		while (i < len && rest[i] != '\n')
			i++;
		if (rest[i] == '\n')
		{
			i = 0;
			line = create_line(rest);
			rest = create_rest(rest, len);
			return (line);
		}
		else
		{
			new_node = ft_lstnew((void *)rest);
			lst = new_node;
			last_node = new_node;
		}
	}
	else
		lst = NULL;
	is_eol = 0;
	nbytes = 1;
	while (!is_eol && nbytes > 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		i = 0;
		if (nbytes > 0)
		{
			while (i != BUFFER_SIZE && buffer[i] != '\n' && buffer[i] != '\0')
				i++;
			if (buffer[i] == '\n' || buffer[i] == '\0')
			{
				is_eol = 1;
				i++;
			}
			len += nbytes;
			buffer[nbytes] = '\0';
			tmp = ft_strdup(buffer);
			new_node = ft_lstnew((void *)tmp);
			if (lst == NULL)
				lst = new_node;
			else
				last_node->next = new_node;
			last_node = new_node;
		}
		else
			return (NULL);
	}
	if (lst == NULL)
		return (NULL);
	new_node = lst;
	final_read = copy_lst(lst, new_node, len);
	line = create_line(final_read);
	rest = create_rest(final_read, len);
	return (line);
}
