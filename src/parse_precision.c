/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 18:00:00 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/21 16:59:29 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

void	parse_precision(char *pos, t_flags *flags, va_list ap)
{
	if (*(pos + flags->flag_length) == '.')
	{
		flags->flag_length += 1;
		flags->flag_char &= ~(FC_ZERO);
		if (ft_isdigit(*(pos + flags->flag_length)))
		{
			flags->precision = (ssize_t)ft_atoi(pos + flags->flag_length);
			flags->flag_length += ft_nbrlen((long)flags->precision);
		}
		else if (*(pos + flags->flag_length) == '*')
		{
			flags->precision = (ssize_t)va_arg(ap, int);
			flags->flag_length += 1;
		}
		else
			flags->precision = 0;
	}
}
