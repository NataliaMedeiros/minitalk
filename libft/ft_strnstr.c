/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmedeiro <nmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:03:38 by nmedeiro          #+#    #+#             */
/*   Updated: 2023/10/27 19:02:05 by nmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (little[i] == '\0')
	{
		return ((char *)&big[i]);
	}
	while (big[i] != '\0' && i < len)
	{
		n = 0;
		while (little[n] != '\0' && big[i + n] == little[n] && i + n < len)
		{
			n++;
		}
		if (little[n] == '\0')
		{
			return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
