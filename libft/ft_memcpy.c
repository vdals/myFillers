/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnydia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:17:02 by jnydia            #+#    #+#             */
/*   Updated: 2019/09/16 18:19:55 by jnydia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char		*s;
	unsigned char			*d;

	s = (unsigned char*)src;
	d = (unsigned char*)dest;
	if (s == 0 && d == 0)
		return (NULL);
	while (n-- > 0)
		*d++ = *s++;
	return (dest);
}
