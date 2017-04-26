/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_wchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 03:23:51 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/23 15:54:04 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

static char	*get_data(wchar_t *tmp, t_flags flags)
{
	char	*data;

	data = NULL;
	if (tmp == NULL)
	{
		if (flags.precision == -1 || flags.precision > 5)
			data = ft_strdup("(null)");
		else
			data = ft_strdup("");
	}
	else
		data = ft_wchartostr(tmp);
	if (!data)
		ft_puterr_and_exit(__FILE__);
	return (data);
}

int			replace_wchar(char *format, char *pos, t_flags flags, va_list ap)
{
	wchar_t	*tmp;
	char	*data;
	int		ret;
	char	*formated_data;

	tmp = va_arg(ap, wchar_t*);
	flags.visual_len = ft_wstrwlen(tmp);
	data = get_data(tmp, flags);
	formated_data = format_data(data, "", &flags);
	ft_strdel(&data);
	ret = replace_format(format, formated_data, pos, flags);
	ft_strdel(&formated_data);
	return (ret);
}
