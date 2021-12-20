/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkais <kkais@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:00:42 by kkais             #+#    #+#             */
/*   Updated: 2021/09/22 13:39:28 by kkais            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (d == s)
		return (d);
	if (s < d)
	{
		i = n;
		while (i--)
			((char *)d)[i] = ((char *)s)[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((char *)d)[i] = ((char *)s)[i];
			i++;
		}
	}
	return (d);
}
