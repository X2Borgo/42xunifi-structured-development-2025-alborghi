/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segmented_runs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:32:15 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/11 16:26:46 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "segmented_runs.h"

int	count_segments(const int *arr, int size)
{
	int	segments;
	int count;
	if (size <= 2 || arr == NULL)
		return (0);
	segments = 0;
	count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == -1)
		{
			if (count >= 3)
				segments++;
			count = 0;
		}
		else if (i == 0)
		{
			count++;
		}
		else if (i > 0 && (arr[i - 1] == -1 || arr[i] > arr[i - 1]))
		{
			count++;
		}
		else if (i > 0 && arr[i] < arr[i - 1] && count < 3)
		{
			count = 1;
		}
	}
	if (count >= 3)
		segments++;
	return (segments);
}
