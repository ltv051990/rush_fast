/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alischyn <alischyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:36:57 by alischyn          #+#    #+#             */
/*   Updated: 2017/12/10 16:45:31 by alischyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "hashmap.h"

void			hotrace_query(const char *key)
{
	t_hashmap_item	*item;
	uint64_t		hash1;
	uint64_t		hash2;
	char			*errormsg;

	hashmap_hash(key, &hash1, &hash2);
	if ((item = hashmap_find(hash1, hash2, key)))
	{
		hash1 = ft_strlen(item->value);
		item->value[hash1] = '\n';
		write(1, item->value, hash1 + 1);
		item->value[hash1] = '\0';
	}
	else
	{
		hash1 = ft_strlen(key);
		errormsg = (char *)malloc(hash1 + 13);
		ft_strcpy(errormsg, key);
		ft_strcpy(errormsg + hash1, " Not found.\n");
		write(1, errormsg, hash1 + 12);
	}
}

int				main(void)
{
	char		*key;
	char		*value;

	hashmap_init();
	while (1)
	{
		get_next_line(&key);
		if (key[0] == '\0')
			break ;
		get_next_line(&value);
		hashmap_insert(key, value);
	}
	free(key);
	while (get_next_line(&key) > 0)
	{
		hotrace_query(key);
		free(key);
	}
	hashmap_free();
	return (0);
}
