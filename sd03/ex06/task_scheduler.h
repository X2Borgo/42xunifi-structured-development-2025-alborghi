/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_scheduler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:17:28 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/13 09:42:29 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TASK_SCHEDULER_H
#define TASK_SCHEDULER_H

#include <stdio.h>

typedef struct Task
{
	int id;
	int CPUload;
	int io_wait;
} Task;

typedef struct TaskList
{
	Task *tasks;
	int count;
} TaskList;

typedef struct TaskProfile
{
	int total_load;
	int total_io_wait;
	int task_count;
} TaskProfile;

typedef struct PriorityMap
{
	int *task_ids;
	int count;
} PriorityMap;

typedef struct ScheduleResult
{
	int core_count;
	int **task_assignments;
	int *core_loads;
} ScheduleResult;

// Analyze task load and I/O behavior. Returns a new TaskProfile or NULL on failure.
struct TaskProfile *profile_tasks(struct TaskList *tasks);
// Compute a priority map from task profiling. Returns a new PriorityMap or NULL on failure.
struct PriorityMap *compute_priorities_mock(struct TaskProfile *profile);
// Return the number of available CPU cores.
int get_available_core_count(void);
// Select the best task to assign next based on the profile. Returns a task ID or -1 on failure.
int select_best_task_for_current_priorities(struct TaskProfile *profile, struct PriorityMap *priorities);
// Create a ScheduleResult structure for the specified number of cores. Returns NULL on failure.
struct ScheduleResult *create_schedule_result(int core_count);
// Update the result schedule with a task assignment.
void update_schedule_entry(struct ScheduleResult *result, int core_id, int task_id);
// Free functions for cleanup
void free_task_profile(struct TaskProfile *profile);
void free_priority_map(struct PriorityMap *priorities);

#endif