/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   average.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:43:28 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/13 10:00:17 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "average.h"

float average(const int *arr, int size)
{
	float sum;
	int div;

	sum = 0;
	if (size <= 0 || arr == NULL)
		return sum;
	div = size;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] >= 0 && arr[i] <= 100)
			sum += arr[i];
		else
			div--;
	}
	return (sum / div);
}
