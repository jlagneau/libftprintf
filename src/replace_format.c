/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 10:57:22 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/18 11:50:44 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		replace_format(char *str, char *data, char *pos, size_t format_len)
{
	char	*after;
	size_t	data_length;
	size_t	after_length;

	after = NULL;
	data_length = ft_strlen(data);
	if (!(after = ft_strdup(str + (pos - str) + format_len)))
		return (-1);
	after_length = ft_strlen(after);
	if (data_length + ft_strlen(str) - format_len > MAX_LENGTH - 1)
		return (-1);
	(void)ft_strcpy(str + (pos - str), data);
	ft_bzero(str + (pos - str) + data_length, after_length + 1);
	(void)ft_strcpy(str + (pos - str) + data_length, after);
	ft_strdel(&after);
	return ((int)ft_strlen(str));
}
