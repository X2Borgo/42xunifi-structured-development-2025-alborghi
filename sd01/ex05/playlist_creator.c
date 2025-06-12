/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playlist_creator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:05:41 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/11 18:15:40 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "playlist_creator.h"

struct Playlist *create_playlist(void)
{
	MoodSettings *mood = NULL;
	FilterSettings *filters = NULL;
	SongData *song = NULL;
	Playlist *playlist = NULL;

	mood = analyze_user_mood();
	if (!mood)
		return NULL;
	filters = default_filters();
	if (!filters)
	{
		free_mood_settings(mood);
		return NULL;
	}
	if (get_mood_variations(mood))
	{
		filters = refine_filters(filters);
		if (!filters)
		{
			free_mood_settings(mood);
			return NULL;
		}
	}
	if (filters_require_popular_song(filters))
		song = fetch_popular_song();
	else
		song = fetch_niche_song();
	if (!song)
	{
		free_mood_settings(mood);
		free_filter_settings(filters);
		return NULL;
	}
	playlist = combine_with_mood_playlist(song, mood);
	free_mood_settings(mood);
	free_filter_settings(filters);
	free_song_data(song);
	return playlist;
}