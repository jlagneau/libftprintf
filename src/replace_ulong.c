/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_ulong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 15:08:42 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/23 04:08:32 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		replace_ulong(char *format, char *pos, t_flags flags, va_list ap)
{
	int		ret;
	char	*data;
	char	*formated_data;

	data = NULL;
	if (!(data = ft_ultoa(va_arg(ap, unsigned long))))
		return (-1);
	flags.visual_len = ft_strlen(data);
	formated_data = format_data(data, "", &flags);
	ft_strdel(&data);
	ret = replace_format(format, formated_data, pos, flags);
	ft_strdel(&formated_data);
	return (ret);
}
