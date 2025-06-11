/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   password_validator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:46:50 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/11 11:37:11 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "password_validator.h"

int	ft_strchr(const char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
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

int main(void)
{
	const char *curr_pw = "OldPassword1@";
	const char *curr_pw2 = "OldPassword1@2";
	const char *new_pw = "Password1@";
	const char *inv_pw = "short1@";
	const char *null_pw = NULL;
	const char *empty_pw = "";
	PasswordHistory history = { .passwords = {NULL, NULL, NULL, NULL} };

	printf("new: %s -> %d\n", new_pw, validate_password(new_pw, &history));
	printf("new: %s -> %d\n", inv_pw, validate_password(inv_pw, &history));
	printf("new: %s -> %d\n", null_pw, validate_password(null_pw, &history));
	printf("new: %s -> %d\n", empty_pw, validate_password(empty_pw, &history));
	printf("new: %s -> %d\n", curr_pw, validate_password(curr_pw, &history));
	printf("new: %s -> %d\n", curr_pw2, validate_password(curr_pw2, &history));
	printf("A+ %.*s|\n", 20, "=");
	return 0;
}