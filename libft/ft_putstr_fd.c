/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmedeiro <nmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:19:08 by nmedeiro          #+#    #+#             */
/*   Updated: 2023/10/26 08:36:44 by nmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Prototype:
		void ft_putstr_fd(char *s, int fd);
	Parameters:
		s: The string to output.
		fd: The file descriptor on which to write.
	External functs:
		write
	Description:
		Outputs the s
*/
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
