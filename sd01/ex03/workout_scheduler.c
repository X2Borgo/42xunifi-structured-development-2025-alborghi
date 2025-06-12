/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workout_scheduler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:50:03 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/11 17:56:14 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "workout_scheduler.h"

struct WorkoutPlan *create_workout_schedule(char *username)
{
	struct UserData *data;
	struct WorkoutPlan *plan;

	data = get_user_data(username);
	if (!data)
		return NULL;
	plan = build_base_plan(data);
	if (!plan)
	{
		free_user_data(data);
		return NULL;
	}
	plan = refine_plan(plan, data);
	if (!plan)
	{
		free_workout_plan(plan);
		free_user_data(data);
		return NULL;
	}
	plan->duration = determine_duration(plan);
	if (plan->duration <= 0)
	{
		free_workout_plan(plan);
		free_user_data(data);
		return NULL;
	}
	for (int day = 0; day < plan->duration; day++)
	{
		assign_daily_exercises(plan, day);
		assign_daily_tips(plan, day);
	}
	free_user_data(data);
	return plan;
}
