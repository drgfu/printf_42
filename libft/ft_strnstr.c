/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkais <kkais@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 01:47:52 by kkais             #+#    #+#             */
/*   Updated: 2021/09/23 17:30:44 by kkais            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*retur(const char *big, size_t j, size_t k)
{
	if (j < k)
		return ((char *)big);
	return ((char *)(big + j - k + 1));
}

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	j;
	size_t	k;
	size_t	l;

	l = ft_strlen(little);
	j = 0;
	k = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[j] != '\0' && j < n)
	{
		if (little[k] == big[j])
		{
			k++;
			if (k == l)
			{
				return (retur(big, j, k));
			}
			if (little[k] != big[j + 1])
				k = k - 1;
		}
		j++;
	}
	return (NULL);
}
