/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krocha-h <krocha-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:53:04 by krocha-h          #+#    #+#             */
/*   Updated: 2023/11/17 15:55:20 by krocha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main () {
	int	fd;


	// fd = open("text_ex", O_RDONLY);
	// printf("Primeira linha: %s", get_next_line(fd));
	// printf("Segunda linha: %s", get_next_line(fd));
	// printf("Terceira linha: %s", get_next_line(fd));
	// printf("Quarta linha: %s", get_next_line(fd));
	// printf("Quinta linha: %s", get_next_line(fd));
	// printf("Sexta linha: %s", get_next_line(fd));
	// printf("Sem mais linhas: %s", get_next_line(fd));
	// close (fd);

	// fd = open("text_ex", O_RDONLY);
	// printf("Arquivo invállido: %s\n", get_next_line(9));
	// printf("Releitura primeira linha: %s\n", get_next_line(fd));
	// printf("Releitura segunda linha: %s\n", get_next_line(fd));
	// close (fd);

	fd = open("1char.txt", O_RDONLY);
	printf("Arquivo invállido:%s\n", get_next_line(9));
	printf("1 char: %s\n", get_next_line(fd));
	printf("Arquivo lido: %s\n", get_next_line(fd));
	close (fd);

	return (0);
}
