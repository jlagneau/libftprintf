/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 10:23:15 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/19 13:12:16 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		replace_int(char *format, char *pos, va_list ap)
{
	int		ret;
	char	*data;

	data = NULL;
	if (!(data = ft_itoa(va_arg(ap, int))))
		return (-1);
	ret = replace_format(format, data, pos, 2);
	ft_strdel(&data);
	return (ret);
}
