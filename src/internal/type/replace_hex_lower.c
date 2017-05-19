/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_hex_lower.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 10:30:34 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/23 04:06:39 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		replace_hex_lower(char *format, char *pos, t_flags flags, va_list ap)
{
	int		ret;
	char	*data;
	char	*formated_data;

	data = NULL;
	if (!(data = ft_ltoa_base(va_arg(ap, unsigned long), BASE_HEX_LOWER)))
		return (-1);
	flags.visual_len = ft_strlen(data);
	formated_data = format_data(data, "0x", &flags);
	ft_strdel(&data);
	ret = replace_format(format, formated_data, pos, flags);
	ft_strdel(&formated_data);
	return (ret);
}
