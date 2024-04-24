/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalia <natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:03:17 by nmedeiro          #+#    #+#             */
/*   Updated: 2023/11/10 15:55:59 by natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*new_dest;
	const char	*new_src;

	i = 0;
	if (dest != NULL || src != NULL)
	{
		new_dest = (char *)dest;
		new_src = (const char *)src;
		while (i < n)
		{
			new_dest[i] = new_src[i];
			i++;
		}
		return (dest);
	}
	else
		return (NULL);
}
