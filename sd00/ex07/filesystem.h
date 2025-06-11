/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:43:10 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/10 17:26:45 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FSNode {
	char *name;
	int size;
	int whoAmI;
	struct FSNode *parent;
	struct FSNode *children;
	struct FSNode *next_sibling;
} FSNode;

int		compute_total_size(FSNode *node);
void	print_structure(const FSNode *node, int indent);
void	free_filesystem(FSNode *node);

#endif