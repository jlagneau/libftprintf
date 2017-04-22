/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 10:57:22 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/21 16:42:15 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
/*
static char	*precision_and_padding(char *tmp, t_flags flags)
{
	char	*tmp2;
	char	*data;
	char	padding_char;

	if (flags.precision >= 0)
		tmp2 = precision(tmp, flags);
	else
		tmp2 = ft_strdup(tmp);
	if (flags.field_width > ft_strlen(tmp2))
	{
		if (flags.flag_char & FC_ZERO && flags.conv_spec & CS_NUMERIC)
			padding_char = '0';
		else
			padding_char = ' ';
		data = padding(tmp2, padding_char, flags);
	}
	else
		data = ft_strdup(tmp2);
	ft_strdel(&tmp2);
	return (data);
}*/

int			replace_format(char *str, char *data, char *pos, t_flags flags)
{
	char	*after;
	size_t	data_length;
	size_t	after_length;

	after = NULL;
	data_length = ft_strlen(data);
	if (!(after = ft_strdup(str + (pos - str) + flags.flag_length)))
		return (-1);
	after_length = ft_strlen(after);
	if (data_length + ft_strlen(str) - flags.flag_length > MAX_LENGTH - 1)
		return (-1);
	(void)ft_strcpy(str + (pos - str), data);
	ft_bzero(str + (pos - str) + data_length, after_length + 1);
	(void)ft_strcpy(str + (pos - str) + data_length, after);
	ft_strdel(&after);
	return ((int)ft_strlen(str));
}
