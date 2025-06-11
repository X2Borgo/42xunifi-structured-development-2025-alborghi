/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   critical_windows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:06:37 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/11 16:34:03 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "critical_windows.h"

int	count_critical_windows(const int *readings, int size)
{
	int	count = 0;
	int	average = 0;
	int	we_win_those = 0;
	int	skip = 0;

	if (size <= 3 || readings == NULL)
		return (0);
	for (int i = 0; i < size; i++)
	{
		if (skip && (i + 1) % 5 != 0)
			continue;
		else if (skip)
			skip = 0;
		if (readings[i] > 150)
		{
			count = 0;
			average = 0;
			skip = 1;
			continue;
		}
		if (readings[i] >= 70)
			count++;
		average += readings[i];
		if (i != 0 && i % 4 == 0)
		{
			if (count >= 3 && average / 5 >= 90)
				we_win_those++;
			count = 0;
			average = 0;
		}
	}
	if (count >= 3 && average / 5 >= 90)
		we_win_those++;
	return (we_win_those);
}
