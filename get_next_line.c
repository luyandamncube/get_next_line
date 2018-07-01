/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 17:07:04 by lmncube           #+#    #+#             */
/*   Updated: 2018/07/01 17:20:39 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_swap(char **store, char *buf)
{
	char	*tempstore;
	
	if (*store)
	{
		tempstore = *store;
		*store = ft_strjoin(tempstore, buf);
		free(tempstore);
		tempstore = NULL;
	}
}

int			ft_nlpos(char *str)
{
	int 	k;

	k = 0;
	while (str[k] != 0)
	{
		if (str[k] == '\n')
			return (k);
		k++;
	}
	return (-1);
}

static int		ft_getline(int fd, char **line, char **leftover)
{
	int		nlpos;
	char	buf[BUFF_SIZE + 1];
	char	*temp;
	int		rd;

	while (0 < (rd = read(fd, buf, BUFF_SIZE)))
	{
		buf[rd] = '\0';
		ft_swap(leftover, buf);
		nlpos = ft_nlpos(*leftover);
		if (0 <= (nlpos))
		{
			break ;
		}
	}
	nlpos = ft_nlpos(*leftover);
	if (nlpos < 0)
		nlpos = ft_strlen(*leftover);
	*line = ft_strsub(*leftover, 0, nlpos);
	temp = *leftover;
	*leftover = ft_strdup(temp + nlpos + 1);
	free(temp);
	return (ft_strlen(*line));
}

int				get_next_line(const int fd, char **line)
{
	static char		*leftover;
	int				bytesread;

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, "", 0) < 0)
		return (-1);
	if (leftover == NULL)
		leftover = ft_strnew(0);
	bytesread = ft_getline(fd, line, &leftover);
	if (!bytesread || line == NULL || *line == '\0')
		return (bytesread);
	if (bytesread < 0)
		return (-1);
	if (*line == NULL && bytesread == 0)
	{
		*line = NULL;
		return (0);
	}
	return (1);
}
