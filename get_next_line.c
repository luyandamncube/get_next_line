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
/*
void		ft_plugleaks(char *s1, char *s2)
{
	ft_strdel(&s1);
	ft_strdel(&s2);
}
*/	
int		ft_getline(int fd, char **store, char **leftover)
{
	char	*nlpos;
	char	buf[BUFF_SIZE + 1];
	char 	*tempstore;
	int	rd;

	if (fd < 0)
		return (-1);
	//templeft = *leftover;
	*store = ft_strdup(*leftover);
	while (0 < (rd = read(fd, buf, BUFF_SIZE)))
	{
		tempstore = *store;			//Placement imoirtant. for EACH iteration the pointer needs to be reset before use
		buf[rd] = '\0';
		if (NULL != (nlpos = ft_memchr(buf, '\n', BUFF_SIZE)))
		{
			*leftover = ft_strdup(nlpos + 1);
			*nlpos = '\0';
			*store = ft_strjoin(tempstore, buf);
			ft_strdel(&tempstore);
			//ft_plugleaks(tempstore, templeft);
			return (ft_strlen(*store));
		}
		*store = ft_strjoin(tempstore, buf);
	}

	ft_strdel(&tempstore);
	//ft_plugleaks(tempstore, templeft);
	return (ft_strlen(*store));
}

int		get_next_line(const int fd, char **line)
{
	static char 	*leftover;				//might need to be static, try static if you have memory corruption
	int 		bytesread;
	
	if (fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	if (leftover == NULL)
	{
		leftover = malloc(BUFF_SIZE + 1);
		ft_bzero(leftover, BUFF_SIZE + 1);
	}
	if (0 < (bytesread = ft_getline(fd, line, &leftover)))
	{
		return (1);
	}
	if (bytesread == 0 && *line[0] == '\n')
		return (1);
	//if (bytesread == 0)
	//	return (0);
	if (bytesread < 0)
		return (-1);
	return (0);
}
