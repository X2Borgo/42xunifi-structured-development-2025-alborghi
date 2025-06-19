/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digitalLibrary.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:59:10 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/18 13:03:31 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIGITAL_LIBRARY_H
#define DIGITAL_LIBRARY_H

#define MAX_SIZE 1000

typedef struct s_book
{
	int id;
	char *title;
	char *author;
} t_book;

typedef struct s_library
{
	t_book books[MAX_SIZE];
	int capacity;
} t_library;

#endif