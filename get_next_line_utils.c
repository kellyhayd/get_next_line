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
/* Allocates and returns a new string, which is the result of the concatenation
of ’s1’ and ’s2’
*
* @param string destination s1
* @param string s2 will be concatenate to s1
* @return New string that contains s1 + s2
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		size;
	char	*dest;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest = malloc (size * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}

/* Locates the first occurrence of c in string
*
* @param string s
* @param character c
* @return A pointer to the matched character or NULL if the character is not found.
*/
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
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
