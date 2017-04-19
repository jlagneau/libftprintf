/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 14:22:09 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/19 12:52:49 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		replace_char(char *format, char *pos, va_list ap)
{
	char	data[2];

	ft_bzero(data, 2);
	data[0] = (char)va_arg(ap, int);
	return (replace_format(format, data, pos, 2));
}
