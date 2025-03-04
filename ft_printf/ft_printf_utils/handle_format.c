/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:00:21 by ikarouat          #+#    #+#             */
/*   Updated: 2025/02/13 19:03:58 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static char	*check_format_specifier(const char s, va_list *ap_p)
{
	char		frmt_spec;

	frmt_spec = s;
	if (frmt_spec == 'd' || frmt_spec == 'i')
		return (ft_putnbr(va_arg(*ap_p, int)));
	else if (frmt_spec == 'u')
		return (ft_put_unsigned_nbr(va_arg(*ap_p, unsigned int)));
	else if (frmt_spec == 'x')
		return (ft_puthex(va_arg(*ap_p, unsigned int), 'x'));
	else if (frmt_spec == 'X')
		return (ft_puthex(va_arg(*ap_p, unsigned int), 'X'));
	else if (frmt_spec == 'p')
		return (ft_putptr(va_arg(*ap_p, uintptr_t)));
	else if (frmt_spec == 's')
		return (va_arg(*ap_p, char *));
	else if (frmt_spec == 'c')
		return (ft_putchar(va_arg(*ap_p, int)), NULL);
	return (NULL);
}

int	handle_format(const char *s, va_list *ap_p, char **buffer)
{
	*buffer = check_format_specifier(*s, ap_p);
	if (!(*buffer))
	{
		if (*s == '%')
			return (ft_putchar('%'));
		else if (*s == 'c')
			return (1);
		else if (*s == 's')
			return (ft_putstr("(null)"));
		else if (*s == 'p')
			return (ft_putstr("(nil)"));
		else
			return (0);
	}
	return (write(1, *buffer, ft_strlen(*buffer)));
}
