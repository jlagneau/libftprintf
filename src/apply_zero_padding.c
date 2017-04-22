/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_zero_padding.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 10:08:23 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/22 10:08:48 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

char		*apply_zero_padding(char *str, t_flags flags)
{
	char	*tmp;
	size_t	len;

	tmp = NULL;
	len = (flags.field_width > ft_strlen(str))
		? flags.field_width - ft_strlen(str) : 0;
	if (flags.flag_char & FC_ZERO && flags.conv_spec & CS_NUMERIC && len > 0)
		tmp = prepend_zeroes(str, len);
	else
		tmp = ft_strdup(str);
	if (!tmp)
		ft_puterr_and_exit(__FILE__);
	return (tmp);
}
