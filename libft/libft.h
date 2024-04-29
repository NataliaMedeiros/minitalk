/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: natalia <natalia@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/09 11:03:51 by natalia       #+#    #+#                 */
/*   Updated: 2024/04/29 14:37:32 by natalia       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define FD 1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_vector
{
	int		size;
	int		capacity;
	char	*str;
}				t_vector;

int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_itoa(int n);
void	ft_putendl_fd(int fd, char *s);
char	*ft_strcat(char *dst, const char *src);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int		ft_putnbr(int nb);
int		ft_putstr(char *str);
int		ft_putnbr_nl(int nb);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_putstr_nl(char *str);

char	*get_next_line(int fd);
size_t	find_nl(char *text);
char	*ft_join_str(char *prev_line, char *text);
int		ft_strlen_nl(const char *s);


int		ft_printf(const	char *format, ...);
int		ft_puthex(unsigned int n, const char type);
int		ft_putpointer(unsigned long n);
int		ft_putunsigned(unsigned int n);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		intlen_base(unsigned long nb, int base);

#endif
