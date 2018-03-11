/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:12:45 by alischyn          #+#    #+#             */
/*   Updated: 2017/12/10 16:32:49 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H

# include <stdio.h>
# include <string.h>

# define BUFF_SIZE (1024 * 1024)

typedef struct	s_gnl_state
{
	size_t				rest_index;
	char				rest[BUFF_SIZE + 1];
	char				*line;
}				t_gnl_state;

int				get_next_line(char **line);

#endif
