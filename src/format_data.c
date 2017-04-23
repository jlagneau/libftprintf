/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:50:37 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/23 04:05:25 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

char		*format_data(char *str, char *prefix, t_flags *flags)
{
	char	*precision;
	char	*zero_padded;
	char	*prefixed;
	char	*prefixed_sign;
	char	*padded;

	precision = apply_precision(str, flags);
	zero_padded = apply_zero_padding(precision, flags);
	ft_strdel(&precision);
	prefixed_sign = apply_prefix_sign(zero_padded, flags);
	ft_strdel(&zero_padded);
	prefixed = apply_prefix(prefixed_sign, prefix, flags);
	ft_strdel(&prefixed_sign);
	padded = apply_padding(prefixed, flags);
	ft_strdel(&prefixed);
	return (padded);
}
