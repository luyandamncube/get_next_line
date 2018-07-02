/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmncube <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 10:38:19 by lmncube           #+#    #+#             */
/*   Updated: 2018/07/02 10:38:48 by lmncube          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 8u
# include "libft/libft.h"
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

int		get_next_line(const int fd, char **line);

#endif
