/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intlen_base.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/27 16:30:19 by natalia       #+#    #+#                 */
/*   Updated: 2024/05/27 16:30:32 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	intlen_base(unsigned long nb, int base)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb /= base;
		len++;
	}
	return (len);
}
