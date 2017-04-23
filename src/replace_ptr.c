/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 10:28:27 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/23 04:05:58 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

static char	*get_data(char *tmp, t_flags *flags)
{
	char	*data;

	data = NULL;
	if (ft_strcmp(tmp, "0") == 0)
	{
		flags->conv_spec = CS_CHAR;
		if (flags->precision == -1 || flags->precision > 4)
			data = ft_strdup("(nil)");
		else
			data = ft_strdup("");
	}
	else
	{
		flags->conv_spec = CS_NUMERIC | CS_UNUMERIC | CS_SPECIAL;
		flags->flag_char |= FC_SHARP;
		data = ft_strdup(tmp);
	}
	if (!data)
		ft_puterr_and_exit(__FILE__);
	return (data);
}

int			replace_ptr(char *format, char *pos, t_flags flags, va_list ap)
{
	int		ret;
	char	*tmp;
	char	*data;
	char	*formated_data;

	tmp = NULL;
	if (!(tmp = ft_ltoa_base(va_arg(ap, unsigned long), BASE_HEX_LOWER)))
		return (-1);
	data = get_data(tmp, &flags);
	flags.visual_len = ft_strlen(data);
	ft_strdel(&tmp);
	formated_data = format_data(data, "0x", &flags);
	ft_strdel(&data);
	ret = replace_format(format, formated_data, pos, flags);
	ft_strdel(&formated_data);
	return (ret);
}
