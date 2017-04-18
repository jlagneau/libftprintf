/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 18:58:30 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/18 11:58:54 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		ft_vdprintf(int fd, const char *format, va_list ap)
{
	int		ret;
	char	str[4096];

	ft_bzero(str, 4096);
	ret = ft_vsprintf(str, format, ap);
	ft_putstr_fd(str, fd);
	(void)fd;
	return (ret);
}
