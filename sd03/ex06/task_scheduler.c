/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_scheduler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:07:31 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/13 10:07:35 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "task_scheduler.h"

struct ScheduleResult *schedule_tasks(struct TaskList *tasks)
{
	TaskProfile *profile;
	PriorityMap *priority_map;

	if (!tasks || tasks->count <= 0 || !tasks->tasks)
		return NULL;
	profile = profile_tasks(tasks);
	if (!profile)
		return NULL;
	priority_map = compute_priorities_mock(profile);
	if (!priority_map)
	{
		free_task_profile(profile);
		return NULL;
	}
	int core_count = get_available_core_count();
	if (core_count <= 0)
	{
		free_task_profile(profile);
		free_priority_map(priority_map);
		return NULL;
	}
	ScheduleResult *result = create_schedule_result(core_count);
	int i = 0;
	while (i < priority_map->count && i < core_count)
	{
		int task_id = select_best_task_for_current_priorities(profile, priority_map);
		if (task_id < 0)
		{
			free_task_profile(profile);
			free_priority_map(priority_map);
			return NULL;
		}
		update_schedule_result(result, i, task_id);
		i++;
	}
	free_task_profile(profile);
	free_priority_map(priority_map);
	return result;
}