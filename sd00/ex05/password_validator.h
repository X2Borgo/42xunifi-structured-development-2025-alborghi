/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   password_validator.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:46:41 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/10 14:02:11 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PASSWORD_VALIDATOR_H
#define PASSWORD_VALIDATOR_H

#include <stdio.h>

#define SPECIAL "@#$%^&*"

typedef enum PwStatus
{
	VALID = 0,
	INVALID = 1
} PwStatus;

#endif