/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   average.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:43:28 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/10 10:49:38 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "average.h"

float	average(const int *arr, int size)
{
	float	sum;
	int		div;

	sum = 0;
	if (size <= 0 || arr == NULL)
		return (sum);
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

int main(void)
{
	int arr[] = {31, 20, 30, 40, 50};
	int size = sizeof(arr) / sizeof(arr[0]);
	float avg = average(arr, size);
	printf("Average: %.2f\n", avg);
	return 0;
}