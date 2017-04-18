/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 19:00:13 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/18 13:18:23 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		ft_vsprintf(char *str, const char *format, va_list ap)
{
	int		length;
	char	*pos;

	str = ft_strcpy(str, format);
	pos = str;
	while (pos)
	{
		if ((pos = ft_strchr(pos, '%')))
			parse_format(str, pos, ap);
	}
	length = (str != NULL) ? (int)ft_strlen(str) : -1;
	return (length);
}
