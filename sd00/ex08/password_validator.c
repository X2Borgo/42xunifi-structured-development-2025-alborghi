/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   password_validator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:46:50 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/13 10:10:31 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "password_validator.h"

int	ft_strchr(const char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return 1;
		s++;
	}
	return 0;
}

PwStatus check_strength(const char *new_pw)
{
	int up;
	int low;
	int num;
	int	spec;
	int i;

	if (!new_pw)
		return INVALID_WEAK;
	up = 0;
	low = 0;
	num = 0;
	spec = 0;
	for (i = 0; new_pw[i] != '\0'; i++)
	{
		if (!up && new_pw[i] >= 'A' && new_pw[i] <= 'Z')
			up = 1;
		else if (!low && new_pw[i] >= 'a' && new_pw[i] <= 'z')
			low = 1;
		else if (!num && new_pw[i] >= '0' && new_pw[i] <= '9')
			num = 1;
		else if (!spec && ft_strchr(SPECIAL, new_pw[i]))
			spec = 1;
	}
	if (i < 8 || !up || !low || !num || !spec)
		return INVALID_WEAK;
	return VALID;
}
