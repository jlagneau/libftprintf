/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_prefix_sign.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 10:09:46 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/22 10:10:17 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

char		*apply_prefix_sign(char *str, t_flags flags)
{
	char	*tmp;
	t_bool	positive;

	tmp = 0;
	if (!(flags.conv_spec & CS_UNUMERIC) && flags.conv_spec & CS_NUMERIC)
	{
		positive = ft_atoi(str) > 0 ? TRUE : FALSE;
		if (positive == TRUE && flags.flag_char & FC_PLUS)
			tmp = ft_strjoin("+", str);
		else if (positive == TRUE && flags.flag_char & FC_SPACE)
			tmp = ft_strjoin(" ", str);
		else
			tmp = ft_strdup(str);
	}
	else
		tmp = ft_strdup(str);
	if (!tmp)
		ft_puterr_and_exit(__FILE__);
	return (tmp);
}
