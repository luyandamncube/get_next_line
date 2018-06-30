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
static void			ft_swap(char **store, char *buf)
{
	char 	*tempstore;

	if (*store)
	{
		tempstore = *store;
		*store = ft_strjoin(tempstore, buf);
		free(tempstore);
		tempstore = NULL;
	}
}

static size_t 			 ft_nlpos(char *str)
{
	size_t 	k;

	k = 0;
	while (str[k] != '\n')
	{
		if (str[k] == '\0')
			return (-1);
		k++;
	}
	return (k);
}
/*

int		ft_getline(int fd, char **store, char **leftover)
{
	char	*nlpos;
	char	buf[BUFF_SIZE + 1];
	
	int		rd;

	*store = ft_strdup(*leftover);
	while (0 < (rd = read(fd, buf, BUFF_SIZE)))
	{
		//tempstore = *store;										//Placement imoirtant. for EACH iteration the pointer needs to be reset before use
		buf[rd] = '\0';
		if (NULL != (nlpos = ft_memchr(buf, '\n', BUFF_SIZE)))
		{
			*leftover = ft_strdup(nlpos + 1);
			*nlpos = '\0';
			ft_swap(store, buf);
			return (ft_strlen(*store));
		}
		ft_swap(store, buf);
	}
	return (ft_strlen(*store));
}
*/

int		ft_getline(int fd, char **line, char **leftover)
{
	size_t	nlpos;
	char	buf[BUFF_SIZE + 1];
	
	int		rd;

	*line = ft_strdup(*leftover);
	while (0 < (rd = read(fd, buf, BUFF_SIZE)))
	{
		//tempstore = *store;										//Placement imoirtant. for EACH iteration the pointer needs to be reset before use
		buf[rd] = '\0';
		ft_swap(leftover, buf);
		if (0 < (nlpos = ft_nlpos(*leftover)))
		{
			break;
		}
		//ft_swap(store, buf);
	}
	*line = ft_strsub(*leftover, 0, nlpos);
	*leftover = ft_strdup(*leftover + nlpos + 1);

	//*nlpos = '\0';
		
	return (ft_strlen(*line));
}

int		get_next_line(const int fd, char **line)
{
	static char 	*leftover;				//might need to be static, try static if you have memory corruption
	int 			bytesread;
	
	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, "", 0) < 0)
		return (-1);
	if (leftover == NULL)
		leftover = ft_strnew(0);
	bytesread = ft_getline(fd, line, &leftover);

	if (bytesread < 0)
		return (-1);
	//if ((line == '\0' || line == NULL) && bytesread == 0) 
	if (*leftover == 0 && bytesread == 0)
		return (0);
	//if (bytesread == 0 && *line[0] == '\n')
		//return (1);

	return (1);
}
