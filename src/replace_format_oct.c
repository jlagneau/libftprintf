/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_format_oct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 10:29:10 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/18 13:04:10 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		replace_format_oct(char *format, char *pos, va_list ap)
{
	int		ret;
	char	*data;

	data = NULL;
	if (!(data = ft_itoa_base(va_arg(ap, unsigned int), BASE_OCTAL)))
		return (-1);
	ret = replace_format(format, data, pos, 2);
	ft_strdel(&data);
	return (ret);
}
