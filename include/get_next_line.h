/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yolee <yolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 01:49:36 by yolee             #+#    #+#             */
/*   Updated: 2022/10/26 20:36:18 by yolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int		buffer_allocate(char **buf);
int		read_to_buffer(char **buf, int fd);
char	*find_line_end(char *buf, int *end_flag);
int		cat_line(char *buf, char **line, size_t *line_len, int *end_flag);
char	*get_next_line(int fd);
#endif
