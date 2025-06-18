/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music_organizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:41:03 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/11 17:46:04 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "music_organizer.h"

struct MusicLibrary *organize_music_library(const char *directory_path)
{
	MusicLibrary *library;
	MusicFile *song;

	if (!directory_path)
		return NULL;
	library = create_music_library();
	if (!library)
		return NULL;
	const char **filenames = scan_directory(directory_path);
	if (!filenames)
		return library;
	for (int i = 0; filenames[i]; i++)
	{
		song = process_music_file(directory_path, filenames[i]);
		if (song)
		{
			update_music_library(library, song);
			free(song->filename);
			free(song->artist);
			free(song->album);
			free(song);
		}
	}
	for (int i = 0; filenames[i]; i++)
		free(filenames[i]);
	free(filenames);
	return library;
}
