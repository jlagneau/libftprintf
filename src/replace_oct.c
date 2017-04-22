/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_oct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 10:29:10 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/21 16:53:03 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		replace_oct(char *format, char *pos, t_flags flags, va_list ap)
{
	int		ret;
	char	*data;
	char	*formated_data;

	data = NULL;
	if (!(data = ft_itoa_base(va_arg(ap, unsigned int), BASE_OCTAL)))
		return (-1);
	formated_data = format_data(data, "0", flags);
	ft_strdel(&data);
	ret = replace_format(format, formated_data, pos, flags);
	ft_strdel(&formated_data);
	return (ret);
}
