/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:13:06 by alischyn          #+#    #+#             */
/*   Updated: 2017/12/10 17:36:39 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"

int			str_concat(char **dest, const char *src)
{
	int		dest_len;
	int		src_len;
	char	*res;

	dest_len = *dest ? ft_strlen(*dest) : 0;
	src_len = 0;
	while (src[src_len] && src[src_len] != '\n')
		src_len++;
	res = (char *)malloc(dest_len + src_len + 1);
	if (*dest)
	{
		ft_strcpy(res, *dest);
		ft_strncat(res, src, src_len);
		free(*dest);
	}
	else
		ft_strncpy(res, src, src_len);
	res[dest_len + src_len] = 0;
	*dest = res;
	return (src_len);
}

static int	ft_fucking_norminette_1(char *newline,
									t_gnl_state *curr,
									char **line)
{
	int					diff;

	diff = newline - &curr->rest[curr->rest_index];
	str_concat(&curr->line, &curr->rest[curr->rest_index]);
	curr->rest_index += diff + 1;
	*line = curr->line;
	curr->line = NULL;
	return (1);
}

static int	ft_fucking_norminette_2(t_gnl_state *curr,
									char **line)
{
	int					nread;

	if ((nread = read(0, curr->rest, BUFF_SIZE)) < 0)
		return (-1);
	curr->rest_index = 0;
	if (curr->line && nread == 0)
	{
		*line = curr->line;
		curr->line = NULL;
		return (1);
	}
	else if (nread == 0)
	{
		*line = NULL;
		curr->line = NULL;
		ft_bzero(curr->rest, sizeof(curr->rest));
		return (0);
	}
	return (get_next_line(line));
}

int			get_next_line(char **line)
{
	static t_gnl_state	curr;
	int					nread;
	char				*newline;

	if (curr.rest[curr.rest_index])
	{
		newline = ft_strchr(&curr.rest[curr.rest_index], '\n');
		if (newline)
			return (ft_fucking_norminette_1(newline, &curr, line));
		else
		{
			str_concat(&curr.line, &curr.rest[curr.rest_index]);
			if ((nread = read(0, curr.rest, BUFF_SIZE)) < 0)
				return (-1);
			curr.rest[nread] = 0;
			curr.rest_index = 0;
			return (get_next_line(line));
		}
	}
	return (ft_fucking_norminette_2(&curr, line));
}
