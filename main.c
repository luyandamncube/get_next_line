/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 15:27:36 by lmncube           #+#    #+#             */
/*   Updated: 2018/06/26 15:29:02 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <stdio.h>

int     main(int argc, char **argv)
{
	int             fd;
	char			*store;
	if (argc != 2)
		printf("USAGE: ./test_ filename\n");
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			printf("Error reading file\n");
		else
		{
			printf("READ: %d\n", get_next_line(fd, &store));
			printf("CONTENT: %s\n", store);
			printf("////////// NEXT ///////////\n");
			printf("READ: %d\n", get_next_line(fd, &store));
			printf("CONTENT: %s\n", store);
			printf("////////// NEXT ///////////\n");
			printf("READ: %d\n", get_next_line(fd, &store));
			printf("CONTENT: %s\n", store);
			printf("////////// NEXT ///////////\n");
			printf("READ: %d\n", get_next_line(fd, &store));
			printf("CONTENT: %s\n", store);
			printf("////////// NEXT ///////////\n");
			printf("READ: %d\n", get_next_line(fd, &store));
			printf("CONTENT: %s\n", store);
			printf("////////// NEXT ///////////\n");
		}
	}
	return (0);
}
