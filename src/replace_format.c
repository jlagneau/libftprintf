/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 10:57:22 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/22 14:17:38 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int			replace_format(char *str, char *data, char *pos, t_flags flags)
{
	char	*after;
	size_t	data_len;
	size_t	after_len;

	after = NULL;
	data_len = ft_strlen(data);
	if (!(after = ft_strdup(str + (pos - str) + flags.flag_length)))
		return (-1);
	after_len = ft_strlen(after);
	if (data_len + ft_strlen(str) - flags.flag_length > FT_PRINTF_MAX_LEN - 1)
	{
		ft_strdel(&after);
		return (-1);
	}
	(void)ft_strcpy(str + (pos - str), data);
	ft_bzero(str + (pos - str) + data_len, after_len + 1);
	(void)ft_strcpy(str + (pos - str) + data_len, after);
	ft_strdel(&after);
	return ((int)ft_strlen(str));
}
