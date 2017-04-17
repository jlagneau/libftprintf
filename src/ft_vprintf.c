/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 18:57:09 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/17 18:57:09 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf.h"

int		ft_vprintf(const char *format, va_list ap)
{
	int		ret;

	ret = ft_vdprintf(STDOUT, format, ap);
	return (ret);
}
