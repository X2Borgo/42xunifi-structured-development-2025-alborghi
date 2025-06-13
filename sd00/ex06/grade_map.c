/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grade_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:13:07 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/13 10:01:07 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grade_map.h"

void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades)
{
	for (int i = 0; i < size; i++)
	{
		if (scores[i] < 0 || scores[i] > 100)
			mapped_grades[i] = "Invalid score";
		else
			mapped_grades[i] = mapper.grades[scores[i]];
	}
}
