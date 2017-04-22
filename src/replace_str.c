/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 09:42:21 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/21 17:50:09 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

static char	*get_data(char *tmp, t_flags flags)
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
		data = ft_strdup(tmp);
	if (!data)
		ft_puterr_and_exit(__FILE__);
	return (data);
}

int			replace_str(char *format, char *pos, t_flags flags, va_list ap)
{
	char	*tmp;
	char	*data;
	int		ret;
	char	*formated_data;

	tmp = va_arg(ap, char*);
	data = get_data(tmp, flags);
	formated_data = format_data(data, "", flags);
	ft_strdel(&data);
	ret = replace_format(format, formated_data, pos, flags);
	ft_strdel(&formated_data);
	return (ret);
}
