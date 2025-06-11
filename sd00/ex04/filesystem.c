/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:43:28 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/10 17:14:32 by alborghi         ###   ########.fr       */
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
	folder->size = 0; // Folders typically have size 0
	folder->whoAmI = 1; // Indicating it's a folder
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

/* void	print_children(const FSNode *parent)
{
	if (!parent || !parent->children)
		return;
	FSNode *child;
	child = parent->children;
	printf("Children of %s:\n", parent->name);
	while (child)
	{
		printf("Child: %s, Size: %d\n", child->name, child->size);
		child = child->next_sibling;
	}
	child = parent->children;
	while (child)
	{
		print_children(child);
		child = child->next_sibling;
	}
}

int main(void)
{
	FSNode *root = create_folder("root");
	FSNode *file1 = create_file("file1.txt", 100);
	FSNode *file2 = create_file("file2.txt", 200);
	FSNode *subfolder = create_folder("subfolder");
	FSNode *subfile1 = create_file("subfile1.txt", 50);
	FSNode *subfile2 = create_file("subfile2.txt", 75);
	FSNode *subsubfolder = create_folder("subsubfolder");
	FSNode *subsubfile = create_file("subsubfile.txt", 25);

	add_child(root, file1);
	add_child(root, file2);
	add_child(root, subfolder);
	add_child(subfolder, subfile1);
	add_child(subfolder, subfile2);
	add_child(subfolder, subsubfolder);
	add_child(subsubfolder, subsubfile);

	print_children(root);

	free(file1->name);
	free(file1);
	free(file2->name);
	free(file2);
	free(subfolder->name);
	free(subfolder);
	free(root->name);
	free(root);

	return 0;
} */