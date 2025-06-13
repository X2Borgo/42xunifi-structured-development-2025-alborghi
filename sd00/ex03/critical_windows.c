/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   critical_windows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:06:37 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/13 11:42:29 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "critical_windows.h"

int count_critical_windows(const int *readings, int size)
{
	int count = 0;
	int average = 0;
	int we_win_those = 0;
	int slide_window[5];

	if (size <= 3 || readings == NULL)
		return 0;
	int i = 0;
	int j = 0;
	while (i < size - 4)
	{
		for (j = 0; j < 5 && i + j < size - 4; j++)
		{
			slide_window[j] = readings[i + j];
		}
		for (j = 0; j < 5 && i + j < size - 4; j++)
		{
			if (slide_window[j] > 150)
				break;
			if (slide_window[j] >= 70)
				count++;
			average += slide_window[j];
		}
		printf("");
		if (count >= 3 && average / 5 >= 90 && (j >= 5 || slide_window[j] <= 150))
			we_win_those++;
		i++;
	}
	return we_win_those;
}
