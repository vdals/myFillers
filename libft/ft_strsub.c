/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnydia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:47:12 by jnydia            #+#    #+#             */
/*   Updated: 2019/09/12 15:08:37 by jnydia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*sstr;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	sstr = ft_strnew(len);
	if (sstr == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		sstr[i] = s[start];
		i++;
		start++;
	}
	sstr[i] = '\0';
	return (sstr);
}
