/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 19:00:13 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/22 14:06:40 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		ft_vsprintf(char *str, const char *format, va_list ap)
{
	char	*pos;

	str = ft_strcpy(str, format);
	pos = str;
	return (search_format(str, pos, ap));
}
