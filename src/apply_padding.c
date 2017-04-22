/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 10:11:06 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/22 10:11:58 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

static char		*get_padding_spaces(size_t size)
{
	char		*tmp;

	tmp = NULL;
	if (!(tmp = ft_strnew(size)))
		ft_puterr_and_exit(__FILE__);
	tmp = ft_memset(tmp, ' ', size);
	return (tmp);
}

char			*apply_padding(char *str, t_flags flags)
{
	char		*ret;
	char		*pad;
	size_t		len;

	pad = NULL;
	ret = NULL;
	len = (flags.field_width > ft_strlen(str))
		? flags.field_width - ft_strlen(str) : 0;
	if (len > 0)
	{
		pad = get_padding_spaces(len);
		if (flags.flag_char & FC_MINUS)
			ret = ft_strjoin(str, pad);
		else
			ret = ft_strjoin(pad, str);
		ft_strdel(&pad);
	}
	else
		ret = ft_strdup(str);
	if (!ret)
		ft_puterr_and_exit(__FILE__);
	return (ret);
}
