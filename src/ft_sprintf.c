/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 18:31:00 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/17 18:31:00 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_sprintf(char *str, const char *format, ...)
{
	int			ret;
	va_list		ap;

	va_start(ap, format);
	ret = ft_vsprintf(str, format, ap);
	va_end(ap);
	return (ret);
}
