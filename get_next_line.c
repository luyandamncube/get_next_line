/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 10:26:19 by lmncube           #+#    #+#             */
/*   Updated: 2018/07/02 10:37:34 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_swapmem(char **store, char *buf)
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

int				ft_nlpos(char *str)
{
	int		k;

	k = 0;
	while (str[k] != 0)
	{
		if (str[k] == '\n')
			return (k);
		k++;
	}
	return (-1);
}

static int		final_check(char *buf)
{
	int i;

	i = -1;
	while (buf[i] != '\0')
		i++;
	return (i);
}

static char		*ft_remainder(char *line)
{
	char	*new;

	new = ft_strchr(line, '\n');
	if ((new != NULL))
	{
		new++;
		new = ft_strdup(new);
	}
	return (new);
}

static int		ft_getline(int fd, char **line, char **leftover)
{
	int		nlpos;
	char	buf[BUFF_SIZE + 1];
	char	*temp;
	int		rd;
	int		final;

	while (0 < (rd = read(fd, buf, BUFF_SIZE)))
	{
		buf[rd] = '\0';
		ft_swapmem(leftover, buf);
		nlpos = ft_nlpos(*leftover);
		if (0 <= (nlpos))
			break ;
	}
	nlpos = ft_nlpos(*leftover);

	final = final_check(*leftover);
	if (nlpos < 0)
	{
		nlpos = ft_strlen(*leftover);
		*line = ft_strsub(*leftover, 0, nlpos);
		temp = *leftover;
		*leftover = ft_strdup("");
	}
	else
	{
		*line = ft_strsub(*leftover, 0, nlpos);
		temp = *leftover;
		*leftover = ft_remainder(temp);
	}
	free(temp);
	if (ft_strlen(*line) == 0 && final > 0)
		return (final);
	return (ft_strlen(*line));
}

int				get_next_line(const int fd, char **line)
{
	static char		*leftover;//[9999];
	int				bytesread;

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, "", 0) < 0)
		return (-1);
	if (leftover/*[fd]*/ == NULL)
		leftover/*[fd]*/ = ft_strnew(0);
	bytesread = ft_getline(fd, line, &leftover/*[fd]*/);
	if (ft_strlen(leftover/*[fd]*/) == 0 && bytesread == 0)
		return (0);
	return (1);
}
