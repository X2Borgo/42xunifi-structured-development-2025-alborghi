/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movie_planner.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:50:25 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/11 16:59:35 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVIE_PLANNER_H
#define MOVIE_PLANNER_H

#include <stdio.h>

typedef struct Preference
{
	char **genre;
} Preference;

typedef struct Movie
{
	char *title;
	char *director;
	int year;
	int duration;
	char **genre;
} Movie;

typedef struct MovieList
{
	Movie *movies;
	int count;
} MovieList;

typedef struct Plan
{
	Movie *movie;
	int day;
	int time;
} Plan;

// Returns user preferences. Returns NULL on failure.
struct Preferences *get_user_preferences(void);
// Returns a list of movies matching the given preferences. Returns NULL on failure.
struct MovieList *find_movies(struct Preferences *prefs);
// Returns a movie night plan from the given list. Returns NULL on failure.
struct Plan *build_plan(struct MovieList *list);

#endif