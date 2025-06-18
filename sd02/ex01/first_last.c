/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:51:58 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/10 10:57:14 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "first_last.h"

void first_last(int arr[], int size, int target, int *first, int *last)
{
	*first = -1;
	*last = -1;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == target)
		{
			if (*first == -1)
				*first = i;
			*last = i;
		}
	}
}
