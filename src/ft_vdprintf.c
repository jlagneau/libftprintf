/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 18:58:30 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/22 14:18:29 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		ft_vdprintf(int fd, const char *format, va_list ap)
{
	int		ret;
	char	str[FT_PRINTF_MAX_LEN];

	ft_bzero(str, FT_PRINTF_MAX_LEN);
	if (ft_strlen(format) > FT_PRINTF_MAX_LEN - 1)
	{
		ft_putstr_fd(str, fd);
		return (-1);
	}
	ret = ft_vsprintf(str, format, ap);
	ft_putstr_fd(str, fd);
	return (ret);
}
