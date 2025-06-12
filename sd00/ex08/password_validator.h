/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   password_validator.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:46:41 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/12 09:59:21 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PASSWORD_VALIDATOR_H
#define PASSWORD_VALIDATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPECIAL "@#$%^&*"

typedef enum PwStatus
{
	VALID = 0,
	INVALID_WEAK = 1,
	INVALID_SIMILAR = 2
} PwStatus;

typedef struct PasswordHistory
{
	char passwords[4][1024];
}	PasswordHistory;

PwStatus check_strength(const char *new_pw);

PwStatus validate_password(const char *new_pw, PasswordHistory *history);

#endif