/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 15:27:36 by lmncube           #+#    #+#             */
/*   Updated: 2018/06/25 16:27:00 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int 			fd;
	char 			*line;
	char 			*left;

	if (argc != 2)
		printf("USAGE: ./test_ filename\n");
	else
	{
		printf("SUCCESS!\n");
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			printf("Error reading file\n");
		printf("STATUS: %d\n", get_next_line(fd, &line);
		printf("OUTPUT: %s\n", line);
		printf("////////// NEXT ///////////\n");
		printf("STATUS: %d\n", get_next_line(fd, &line);
		printf("OUTPUT: %s\n", line);
		printf("////////// NEXT ///////////\n");
		printf("STATUS: %d\n", get_next_line(fd, &line);
		printf("OUTPUT: %s\n", line);
		printf("////////// NEXT ///////////\n");
		printf("STATUS: %d\n", get_next_line(fd, &line);
		printf("OUTPUT: %s\n", line);
		printf("////////// NEXT ///////////\n");
	}	
	return (0);

}
