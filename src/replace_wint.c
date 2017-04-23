/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_wint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 11:00:00 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/23 11:08:21 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int			replace_wint(char *format, char *pos, t_flags flags, va_list ap)
{
	wint_t	tmp;
	char	*data;
	int		ret;
	char	*formated_data;

	tmp = va_arg(ap, wint_t);
	flags.visual_len = 1;
	data = ft_winttostr(tmp);
	formated_data = format_data(data, "", &flags);
	ret = replace_format(format, formated_data, pos, flags);
	ft_strdel(&formated_data);
	return (ret);
}
