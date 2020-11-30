/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnydia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:11:48 by jnydia            #+#    #+#             */
/*   Updated: 2019/09/09 17:12:35 by jnydia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		n = 0;
		while (haystack[i + n] && i + n < len &&
				needle[n] && haystack[i + n] == needle[n])
			n++;
		if (needle[n] == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
