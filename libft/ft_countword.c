/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnydia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 19:22:28 by jnydia            #+#    #+#             */
/*   Updated: 2020/06/13 19:22:34 by jnydia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countword(char const *s, char c)
{
	int		cpt;

	cpt = 0;
	if (!s)
		return (cpt);
	while (*s)
	{
		if (*s != c)
		{
			cpt++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (cpt);
}
