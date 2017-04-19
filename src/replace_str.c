/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 09:42:21 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/19 13:11:47 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		replace_str(char *format, char *pos, va_list ap)
{
	char	*data;

	data = va_arg(ap, char*);
	return (replace_format(format, data, pos, 2));
}
