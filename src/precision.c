/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 18:15:06 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/23 04:04:33 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

static char	*str_precision(char *str, t_flags *flags)
{
	char	*tmp;

	tmp = NULL;
	if (flags->precision < (ssize_t)flags->visual_len)
	{
		/* TODO ft_wstrnew & ft_wstrncpy */
		tmp = ft_strnew((size_t)flags->precision);
		tmp = ft_strncpy(tmp, str, (size_t)flags->precision);
	}
	else
		tmp = ft_strdup(str);
	if (!tmp)
		ft_puterr_and_exit(__FILE__);
	return (tmp);
}

static char	*num_precision(char *str, t_flags *flags)
{
	char	*tmp;
	size_t	len;

	tmp = NULL;
	if (!ft_strcmp(str, "0") && flags->precision == 0)
	{
		tmp = ft_strdup("");
		flags->visual_len = 0;
	}
	else if (flags->precision > (ssize_t)flags->visual_len)
	{
		len = (size_t)flags->precision - flags->visual_len;
		tmp = prepend_zeroes(str, len);
		flags->visual_len += len;
	}
	else
		tmp = ft_strdup(str);
	if (!tmp)
		ft_puterr_and_exit(__FILE__);
	return (tmp);
}

char		*precision(char *str, t_flags *flags)
{
	char	*tmp;

	if (flags->conv_spec & CS_CHAR)
		tmp = str_precision(str, flags);
	else
		tmp = num_precision(str, flags);
	return (tmp);
}
