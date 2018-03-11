/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 17:51:51 by alischyn          #+#    #+#             */
/*   Updated: 2017/12/10 17:46:13 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hashmap.h"

t_hashmap_item	**g_hashmap = NULL;

void			hashmap_hash(const char *str, uint64_t *h1p, uint64_t *h2p)
{
	size_t		hash1;
	size_t		hash2;
	char		c;

	hash1 = 0xdeadbeef;
	hash2 = 0xabcdef123;
	while ((c = *str))
	{
		hash1 += (hash1 << 16) + c;
		hash2 += (hash2 << 15) ^ c;
		str++;
	}
	*h1p = hash1 % HASHMAP_SIZE;
	*h2p = hash2;
}

t_hashmap_item	*hashmap_find(uint64_t hash1, uint64_t hash2, const char *key)
{
	t_hashmap_item	*item;

	if ((item = g_hashmap[hash1]))
	{
		while (item)
		{
			if (item->hash2 == hash2 && ft_strcmp(item->key, key) == 0)
				return (item);
			item = item->next;
		}
	}
	return (NULL);
}

void			hashmap_insert(char *key, char *value)
{
	t_hashmap_item	*item;
	uint64_t		hash1;
	uint64_t		hash2;

	hashmap_hash(key, &hash1, &hash2);
	if ((item = hashmap_find(hash1, hash2, key)))
	{
		free(item->value);
		item->value = value;
	}
	else
	{
		item = (t_hashmap_item *)malloc(sizeof(t_hashmap_item));
		item->hash2 = hash2;
		item->key = key;
		item->value = value;
		item->next = g_hashmap[hash1];
		g_hashmap[hash1] = item;
	}
}
