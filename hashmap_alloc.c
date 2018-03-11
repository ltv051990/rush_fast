/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_alloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:31:22 by alischyn          #+#    #+#             */
/*   Updated: 2017/12/10 15:38:09 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

void			hashmap_init(void)
{
	g_hashmap = (t_hashmap_item **)malloc(HASHMAP_SIZE_BYTES);
	ft_bzero(g_hashmap, HASHMAP_SIZE_BYTES);
}

void			hashmap_free(void)
{
	int				i;
	t_hashmap_item	*curr;
	t_hashmap_item	*next;

	i = 0;
	while (i < HASHMAP_SIZE)
	{
		curr = g_hashmap[i];
		while (curr)
		{
			next = curr->next;
			free(curr->key);
			free(curr->value);
			free(curr);
			curr = next;
		}
		i += 1;
	}
	free(g_hashmap);
}
