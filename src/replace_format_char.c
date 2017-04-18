/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_format_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 14:22:09 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/18 14:26:43 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		replace_format_char(char *format, char *pos, va_list ap)
{
	char	data[2];

	ft_bzero(data, 2);
	data[0] = (char)va_arg(ap, int);
	return (replace_format(format, data, pos, 2));
}