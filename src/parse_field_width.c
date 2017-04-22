/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_field_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 12:38:41 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/20 18:09:32 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

void	parse_field_width(char *pos, t_flags *flags, va_list ap)
{
	if (ft_isdigit(*(pos + flags->flag_length)))
	{
		flags->field_width = (size_t)ft_atoi(pos + flags->flag_length);
		flags->flag_length += ft_nbrlen((long)flags->field_width);
	}
	else if (*(pos + flags->flag_length) == '*')
	{
		flags->field_width = (size_t)va_arg(ap, int);
		flags->flag_length += 1;
	}
}
