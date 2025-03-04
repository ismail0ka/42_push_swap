/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:35:51 by ikarouat          #+#    #+#             */
/*   Updated: 2025/02/13 17:07:49 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int		handle_format(const char *s, va_list *ap_p, char **buffer);
char	*ft_putnbr(int n);
char	*ft_puthex(unsigned int n, char x);
char	*ft_put_unsigned_nbr(unsigned int n);
char	*ft_putptr(uintptr_t ptr);
int		ft_putstr(const char *s);
int		ft_putchar(const char c);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
#endif //FT_PRINTF_UTILS_H
