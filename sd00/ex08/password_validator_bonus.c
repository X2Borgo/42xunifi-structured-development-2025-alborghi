/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   password_validator_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alborghi <alborghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:32:38 by alborghi          #+#    #+#             */
/*   Updated: 2025/06/13 10:11:12 by alborghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "password_validator.h"

int ft_strlen(const char *s)
{
	int len = 0;
	while (s[len])
		len++;
	return len;
}

void	ft_strncpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; i < MAX_LENGTH && src[i] != '\0'; i++)
		dest[i] = src[i];
	for (; i < MAX_LENGTH; i++)
		dest[i] = '\0';
}

int passcmp(const char *s1, const char *s2)
{
	int	diff;
	int	len1;
	int	len2;
	
	if (!s1 || !s2)
		return 2;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	diff = (len1 > len2) ? len1 - len2 : len2 - len1;
	for (int i = 0; i < len1 && i < len2 && diff < 2; i++)
		diff += s1[i] != s2[i];
	return diff;
}

void	append_password(const char *new_pw, PasswordHistory *history)
{
	if (!new_pw || !history)
		return;
	for (int i = 2; i; i--)
	{
		if (history->passwords[i - 1])
			ft_strncpy(history->passwords[i], history->passwords[i - 1]);
		else
			break;
	}
	ft_strncpy(history->passwords[0], new_pw);
}

PwStatus validate_password(const char *new_pw, PasswordHistory *history)
{
	if (!new_pw || check_strength(new_pw) != VALID)
		return INVALID_WEAK;
	for (int i = 0; history->passwords[i] && i < 3; i++)
	{
		if (passcmp(new_pw, history->passwords[i]) < 2)
			return INVALID_SIMILAR;
	}
	append_password(new_pw, history);
	return VALID;
}