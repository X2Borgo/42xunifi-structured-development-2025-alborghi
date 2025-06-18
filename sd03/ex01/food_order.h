/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   food_order.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:30:08 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/11 17:36:47 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOOD_ORDER_H
#define FOOD_ORDER_H

#include <stdio.h>

typedef struct OrderRequest
{
	char *restaurant_name;
	char *order_details;
} OrderRequest;

typedef struct OrderConfirmation
{
	char *confirmation_number;
	char *status_message;
} OrderConfirmation;

// Checks if the restaurant is open based on the order. Returns 1 if open, 0 if closed.
int check_restaurant_status(struct OrderRequest *request);
// Creates a confirmation for an immediate order. Returns NULL on failure.
struct OrderConfirmation *create_standard_confirmation(void);
// Creates a confirmation for a future (pre-order). Returns NULL on failure.
struct OrderConfirmation *create_preorder_confirmation(void);
// Sends the confirmation to the user.
void send_confirmation_notification(struct OrderConfirmation *confirmation);

#endif