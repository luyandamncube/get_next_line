/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 13:15:58 by lmncube           #+#    #+#             */
/*   Updated: 2018/06/26 14:33:25 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_getline(int fd, void **store, void **leftover)
{
	char	*nlpos;
	char	buf[BUFF_SIZE + 1];
	int		rd;

	if (fd < 0)
		return (-1);
	*store = ft_strdup("");
	*store = ft_strcpy(*store, *leftover);
	while (0 < (rd = read(fd, buf, BUFF_SIZE)))
	{
		buf[rd] = '\0';
		if (NULL != (nlpos = ft_memchr(buf, '\n', BUFF_SIZE)))
		{
			*leftover = ft_strcpy(*leftover, nlpos + 1);
			*nlpos = '\0';
			*store = ft_strjoin(*store, buf);
			return (ft_strlen(*store));
		}
		*store = ft_strjoin(*store, buf);
	}
	return (ft_strlen(*store));
}

int		get_next_line(const int fd, char **line)
{
	void 			*leftover;
	void			*store;
	int 			ret;
	if (leftover == NULL)
	{
		leftover = malloc(BUFF_SIZE + 1);
		ft_bzero(leftover, BUFF_SIZE + 1);
	}
	if (fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (0 < (ret = ft_getline(fd, &store, &leftover)))
		return (1);
	if (ret == 0)
		return (0);
	if (ret < 0)
		return (-1);
	return (0);
}
/*
int     main(int argc, char **argv)
{
	int             fd;
	char            *line;
	char            *left;

	if (argc != 2)
		printf("USAGE: ./test_ filename\n");
	else
	{
		printf("SUCCESS!\n");
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			printf("Error reading file\n");
		printf("STATUS: %d\n", ft_getline(fd, &line, &left));
		printf("OUTPUT: %s\n", line);
		printf("////////// NEXT ///////////\n");
		printf("STATUS: %d\n", ft_getline(fd, &line, &left));
		printf("OUTPUT: %s\n", line);
		printf("////////// NEXT ///////////\n");
		printf("STATUS: %d\n", ft_getline(fd, &line, &left));
		printf("OUTPUT: %s\n", line);
		printf("////////// NEXT ///////////\n");
		printf("STATUS: %d\n", ft_getline(fd, &line, &left));
		printf("OUTPUT: %s\n", line);
		printf("////////// NEXT ///////////\n");
	}
	return (0);
}*/
