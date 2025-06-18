/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music_organizer.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:39:55 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/11 17:47:53 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUSIC_ORGANIZER_H
#define MUSIC_ORGANIZER_H

#include <stdio.h>

typedef struct MusicFile
{
	char *filename;
	char *artist;
	char *album;
	int duration;
} MusicFile;

typedef struct MusicLibrary
{
	MusicFile **songs;
	int count;
} MusicLibrary;

// Creates and returns a new music library. Returns NULL on fail
struct MusicLibrary *create_music_library();
// Scans a directory for music files. Returns a NULL terminated array of filenames.
const char **scan_directory(const char *directory_path);
// Processes a single music file. Returns a data structure representing the processed file.
struct MusicFile *process_music_file(const char *directory_path, const char *filename);
// Updates the music library with the processed music file information.
void update_music_library(struct MusicLibrary *library, struct MusicFile *song);

#endif