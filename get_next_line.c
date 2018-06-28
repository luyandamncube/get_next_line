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

int		ft_getline(int fd, char **store, char **leftover)
{
	char	*nlpos;
	char	buf[BUFF_SIZE + 1];
	int		rd;

	if (fd < 0)
		return (-1);
	*store = ft_strdup("");
	*store = ft_strcpy(*store, *leftover);		//memory trick. strcpy causes buffer overrun in some cases and essentially corrupts other memory
	//*store = ft_strdup(*leftover);
	while (0 < (rd = read(fd, buf, BUFF_SIZE)))
	{
		buf[rd] = '\0';
		if (NULL != (nlpos = ft_memchr(buf, '\n', BUFF_SIZE)))
		{
			*leftover = ft_strcpy(*leftover, nlpos + 1);
			//*leftover = ft_strdup(nlpos + 1);
			*nlpos = '\0';
			*store = ft_strjoin(*store, buf);
			//printf("FOUND: %s\n", *store);
			return (ft_strlen(*store));
		}
		*store = ft_strjoin(*store, buf);
		//printf("NOT FOUND: %s\n", *store);
	}
	return (ft_strlen(*store));
}

int		get_next_line(const int fd, char **line)
{
	static char 	*leftover;							//might need to be static, try static if you have memory corruption
	int 			ret;
	
	if (leftover == NULL)
	{
		leftover = malloc(BUFF_SIZE + 1);
		ft_bzero(leftover, BUFF_SIZE + 1);
	}
	if (fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (0 < (ret = ft_getline(fd, line, &leftover)))
		return (1);
	if (ret == 0)
		return (0);
	if (ret < 0)
		return (-1);
	return (0);
}