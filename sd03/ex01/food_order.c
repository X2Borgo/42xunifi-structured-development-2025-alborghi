/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   food_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:30:02 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/11 17:39:15 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "food_order.h"

int process_food_order(struct OrderRequest *request)
{
	int status;
	OrderConfirmation *confirmation = NULL;

	if (!request || !request->restaurant_name || !request->order_details)
		return 0;
	status = check_restaurant_status(request);
	if (status == 1)
		confirmation = create_standard_confirmation();
	else if (status == 0)
		confirmation = create_preorder_confirmation();
	if (!confirmation)
		return 0;
	send_confirmation_notification(confirmation);
	free(confirmation->confirmation_number);
	free(confirmation->status_message);
	free(confirmation);
	return 1;
}
