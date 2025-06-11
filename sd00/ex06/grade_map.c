/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grade_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:13:07 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/11 11:46:47 by alborghi         ###   ########.fr       */
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

/* int main(void)
{
	GradeMapper mapper;

	for (int i = 0; i <= 100; i++)
	{
		if (i >= 97)
			mapper.grades[i] = "A+";
		else if (i >= 93)
			mapper.grades[i] = "A";
		else if (i >= 90)
			mapper.grades[i] = "A-";
		else if (i >= 87)
			mapper.grades[i] = "B+";
		else if (i >= 83)
			mapper.grades[i] = "B";
		else if (i >= 80)
			mapper.grades[i] = "B-";
		else if (i >= 77)
			mapper.grades[i] = "C+";
		else if (i >= 73)
			mapper.grades[i] = "C";
		else if (i >= 70)
			mapper.grades[i] = "C-";
		else if (i >= 67)
			mapper.grades[i] = "D+";
		else if (i >= 63)
			mapper.grades[i] = "D";
		else if (i >= 60)
			mapper.grades[i] = "D-";
		else
			mapper.grades[i] = "F";
	}
	mapper.grades[101] = NULL;
	int scores[] = {97, 87, 77, 67, 55, 45, 105, -5};
	const int size = sizeof(scores) / sizeof(scores[0]);
	const char *mapped_grades[size];
	map_scores(scores, size, mapper, mapped_grades);
	for (int i = 0; i < size; i++)
	{
		printf("Score: %d, Grade: %s\n", scores[i], mapped_grades[i]);
	}
	return 0;
} */
