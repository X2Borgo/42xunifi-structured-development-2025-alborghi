/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movie_planner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:58:19 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/11 17:07:16 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movie_planner.h"

void	free_preferences(Preference *pref)
{
	if (pref)
	{
		if (pref->genre)
		{
			for (int i = 0; pref->genre[i]; i++)
				free(pref->genre[i]);
		}
		free(pref);
	}
}

void	free_movie_list(MovieList *movie_list)
{
	if (!movie_list)
		return;
	if (!movie_list->movies)
	{
		free(movie_list);
		return;
	}
	for (int i = 0; i < movie_list->count; i++)
	{
		free(movie_list->movies[i].title);
		free(movie_list->movies[i].director);
		if (movie_list->movies[i].genre)
		{
			for (int j = 0; movie_list->movies[i].genre[j]; j++)
				free(movie_list->movies[i].genre[j]);
		}
		free(movie_list->movies[i].genre);
	}
	free(movie_list->movies);
	free(movie_list);
}

struct Plan *create_movie_night_plan(void)
{
	Preference *pref;
	MovieList *movie_list;
	Plan *plan;

	pref = get_user_preferences();
	if (!pref)
		return NULL;
	movie_list = find_movies(pref);
	if (!movie_list)
	{
		free_preferences(pref);
		return NULL;
	}
	plan = build_plan(movie_list);
	if (!plan)
	{
		free_preferences(pref);
		free_movie_list(movie_list);
		return NULL;
	}
	free_preferences(pref);
	free_movie_list(movie_list);
	return plan;
}