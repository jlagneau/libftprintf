/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 14:22:09 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/23 04:06:47 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		replace_char(char *format, char *pos, t_flags flags, va_list ap)
{
	int		ret;
	char	data[2];
	char	*formated_data;

	ft_bzero(data, 2);
	data[0] = (char)va_arg(ap, int);
	flags.visual_len = ft_strlen(data);
	formated_data = format_data(data, "", &flags);
	ret = replace_format(format, formated_data, pos, flags);
	ft_strdel(&formated_data);
	return (ret);
}
