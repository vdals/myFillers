/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnydia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:54:16 by jnydia            #+#    #+#             */
/*   Updated: 2019/09/16 18:20:20 by jnydia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MAX_LONG 9223372036854775807

int	ft_atoi(const char *str)
{
	unsigned long long		res;
	int						neg;
	int						c;

	neg = 1;
	res = 0;
	c = 0;
	while (*str == ' ' || *str == '\f' || *str == '\t' ||
			*str == '\n' || *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		c++;
		res = res * 10 + (*str - 48);
		str++;
		if ((res >= MAX_LONG && neg > 0) || c >= 20)
			return (-1);
		if (res > MAX_LONG && neg < 0)
			return (0);
	}
	return (res * neg);
}
