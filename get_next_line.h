/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 13:11:31 by lmncube           #+#    #+#             */
/*   Updated: 2018/06/25 16:20:06 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4u
# include "libft/libft.h"
# include <fcntl.h>

int		        get_next_line(const int fd, char **line);
int		ft_getline(int fd, char **store, char **leftover);

#endif
