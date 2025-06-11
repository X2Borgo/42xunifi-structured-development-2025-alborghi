/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:47:58 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/10 17:30:05 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filesystem.h"

int compute_total_size(FSNode *node)
{
	int total_size;
	FSNode *tmp;

	if (!node)
		return 0;
	tmp = node->children;
	total_size = 0;
	while (tmp)
	{
		if (tmp->whoAmI == 1)
			total_size += compute_total_size(tmp);
		else
			total_size += tmp->size;
		tmp = tmp->next_sibling;
	}
	return total_size;
}

void print_structure(const FSNode *node, int indent)
{
	FSNode *tmp;

	if (!node)
		return;
	printf("%*s%s (Size: %d)\n", indent, "", node->name, node->size);
	tmp = node->children;
	while (tmp)
	{
		if (tmp->whoAmI == 1)
			print_structure(tmp, indent + 4);
		else
			printf("%*s%s (Size: %d)\n", indent + 4, "", tmp->name, tmp->size);
		tmp = tmp->next_sibling;
	}
}

void free_filesystem(FSNode *node)
{
	FSNode *tmp;
	FSNode *next;
	if (!node)
		return;
	free(node->name);
	tmp = node->children;
	while (tmp)
	{
		next = tmp->next_sibling;
		if (tmp->whoAmI == 1)
			free_filesystem(tmp);
		else
		{
			free(tmp->name);
			free(tmp);
		}
		tmp = next;
	}
	free(node);
}
