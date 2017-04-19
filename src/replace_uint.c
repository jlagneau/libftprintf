/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 10:44:29 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/19 13:11:37 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		replace_uint(char *format, char *pos, va_list ap)
{
	int		ret;
	char	*data;

	data = NULL;
	if (!(data = ft_uitoa(va_arg(ap, unsigned int))))
		return (-1);
	ret = replace_format(format, data, pos, 2);
	ft_strdel(&data);
	return (ret);
}
