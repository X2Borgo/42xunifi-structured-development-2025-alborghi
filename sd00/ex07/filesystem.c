/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:43:28 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/13 10:01:34 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filesystem.h"

FSNode *create_file(const char *name, int size)
{
	FSNode *file = malloc(sizeof(FSNode));
	if (!file)
		return NULL;
	file->name = strdup(name);
	file->size = size;
	file->whoAmI = 0;
	file->parent = NULL;
	file->children = NULL;
	file->next_sibling = NULL;
	return file;
}

FSNode *create_folder(const char *name)
{
	FSNode *folder = malloc(sizeof(FSNode));
	if (!folder)
		return NULL;
	folder->name = strdup(name);
	folder->size = 0;
	folder->whoAmI = 1;
	folder->parent = NULL;
	folder->children = NULL;
	folder->next_sibling = NULL;
	return folder;
}

void add_child(FSNode *parent, FSNode *child)
{
	if (!parent || !child)
		return;
	child->parent = parent;
	if (parent->children == NULL)
	{
		parent->children = child;
	}
	else
	{
		FSNode *sibling = parent->children;
		while (sibling->next_sibling != NULL)
			sibling = sibling->next_sibling;
		sibling->next_sibling = child;
	}
}

FSNode *get_children(const FSNode *parent)
{
	if (!parent)
		return NULL;
	return parent->children;
}

FSNode *get_sibling(const FSNode *node)
{
	if (!node || !node->parent)
		return NULL;
	return node->parent->children;
}
