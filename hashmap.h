/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 17:51:34 by alischyn          #+#    #+#             */
/*   Updated: 2017/12/10 16:45:45 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HASHMAP_H
# define __HASHMAP_H

# include <stdlib.h>
# include <stdint.h>
# include "libft.h"

# define HASHMAP_SIZE	153089
# define HASHMAP_SIZE_BYTES	((HASHMAP_SIZE) * sizeof(void *))

typedef struct	s_hashmap_item
{
	uint64_t				hash2;
	char					*key;
	char					*value;
	struct s_hashmap_item	*next;
}				t_hashmap_item;

t_hashmap_item	**g_hashmap;

void			hashmap_init(void);
void			hashmap_free(void);

void			hashmap_hash(const char *str, uint64_t *hash1, uint64_t *hash2);
t_hashmap_item	*hashmap_find(uint64_t hash1, uint64_t hash2, const char *key);
void			hashmap_insert(char *key, char *value);

#endif
