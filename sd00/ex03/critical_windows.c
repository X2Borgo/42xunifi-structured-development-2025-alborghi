/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   critical_windows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:06:37 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/10 12:39:51 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "critical_windows.h"

int	count_critical_windows(const int *readings, int size)
{
	int	count;
	int	average;
	int	we_win_those;

	if (size <= 3 || readings == NULL)
		return (0);
	count = 0;
	average = 0;
	we_win_those = 0;
	for (int i = 0; i < size; i++)
	{
		if (readings[i] > 150)
		{
			count = 0;
			average = 0;
			i += 4 - i % 5;
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
			printf("updated!\n");
		}
	}
	if (count >= 3 && average / 5 >= 90)
		we_win_those++;
	return (we_win_those);
}
