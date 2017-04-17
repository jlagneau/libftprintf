/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 18:29:57 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/17 18:29:57 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf.h"

int		ft_dprintf(int fd, const char *format, ...)
{
	int			ret;
	va_list		ap;

	ret = ft_vdprintf(fd, format, ap);
	return (ret);
}
