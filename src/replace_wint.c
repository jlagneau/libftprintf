/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_wint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 11:00:00 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/23 13:58:45 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int			replace_wint(char *format, char *pos, t_flags flags, va_list ap)
{
	wchar_t	tmp[2];
	char	*data;
	int		ret;
	char	*formated_data;

	tmp[0] = (wchar_t)va_arg(ap, wint_t);
	tmp[1] = 0;
	flags.visual_len = 1;
	flags.data = &tmp;
	data = ft_wchartostr(tmp);
	formated_data = format_data(data, "", &flags);
	ret = replace_format(format, formated_data, pos, flags);
	ft_strdel(&formated_data);
	return (ret);
}
