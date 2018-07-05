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
# include <fcntl.h>

int				ft_nlpos(char *str);

int     main(int argc, char **argv)
{
	int             fd;
	char			*store;
	char			*nlpos;
	int 			result;
	if (argc != 2)
		printf("USAGE: ./test_ filename\n");
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			printf("Error reading file\n");

		while ((result = get_next_line(fd, &store)) == 1)
		{
			printf("RES: %d\n, ", result);
			nlpos = ft_strchr(store, '\n');
			printf("CONTENT: %s\n", store);

			printf("\n////////// NEXT LINE ///////////\n");

		}
	}
		return (0);
}