/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 18:15:06 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/21 17:07:35 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

static char	*str_precision(char *str, t_flags flags)
{
	char	*tmp;

	tmp = NULL;
	if (flags.precision < (ssize_t)ft_strlen(str))
	{
		if (!(tmp = ft_strnew((size_t)flags.precision)))
			ft_puterr_and_exit(__FILE__);
		tmp = ft_strncpy(tmp, str, (size_t)flags.precision);
	}
	else
	{
		if (!(tmp = ft_strdup(str)))
			ft_puterr_and_exit(__FILE__);
	}
	return (tmp);
}

static char	*num_precision(char *str, t_flags flags)
{
	char	*tmp;
	size_t	len;

	tmp = NULL;
	if (!ft_strcmp(str, "0") && flags.precision == 0)
	{
		if (!(tmp = ft_strdup("")))
			ft_puterr_and_exit(__FILE__);
	}
	else if (flags.precision > (ssize_t)ft_strlen(str))
	{
		len = (size_t)flags.precision - ft_strlen(str);
		if (!(tmp = prepend_zeroes(str, len)))
			ft_puterr_and_exit(__FILE__);
	}
	else
	{
		if (!(tmp = ft_strdup(str)))
			ft_puterr_and_exit(__FILE__);
	}
	return (tmp);
}

char		*precision(char *str, t_flags flags)
{
	char	*tmp;

	if (flags.conv_spec & CS_CHAR)
		tmp = str_precision(str, flags);
	else
		tmp = num_precision(str, flags);
	return (tmp);
}
