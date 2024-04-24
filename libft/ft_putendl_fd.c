/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmedeiro <nmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:18:51 by nmedeiro          #+#    #+#             */
/*   Updated: 2023/10/26 17:45:48 by nmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Prototype:
		void ft_putendl_fd(char *s, int fd);
	Parameters:
		s: The string to output.
		fd: The file descriptor on which to write.
	External functs:
		write
	Description:
		Outputs the string ’s’ to the given file descriptor followed by a newline.
*/
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}
