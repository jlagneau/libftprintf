/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 18:15:06 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/23 14:12:20 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

static char		*wstr_precision(t_flags *flags)
{
	char		*tmp;
	wchar_t		*wtmp;

	if (!(wtmp = ft_wstrnew((size_t)flags->precision)))
		ft_puterr_and_exit(__FILE__);
	wtmp = ft_wstrncpy(wtmp, flags->data, (size_t)flags->precision);
	tmp = ft_wchartostr(wtmp);
	ft_wstrdel(&wtmp);
	return (tmp);
}

static char		*str_precision(char *str, t_flags *flags)
{
	char		*tmp;
	wchar_t		*wtmp;

	tmp = NULL;
	wtmp = NULL;
	if (flags->precision < (ssize_t)flags->visual_len)
	{
		flags->visual_len = (size_t)flags->precision;
		if (flags->conv_spec & CS_WCHAR)
			tmp = wstr_precision(flags);
		else
		{
			tmp = ft_strnew((size_t)flags->precision);
			tmp = ft_strncpy(tmp, str, (size_t)flags->precision);
		}
	}
	else
		tmp = ft_strdup(str);
	if (!tmp)
		ft_puterr_and_exit(__FILE__);
	return (tmp);
}

static char		*num_precision(char *str, t_flags *flags)
{
	char		*tmp;
	size_t		len;

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

char			*precision(char *str, t_flags *flags)
{
	char		*tmp;

	if (flags->conv_spec & CS_CHAR)
		tmp = str_precision(str, flags);
	else
		tmp = num_precision(str, flags);
	return (tmp);
}
