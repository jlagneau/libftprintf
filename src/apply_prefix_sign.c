/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_prefix_sign.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 10:09:46 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/23 04:08:56 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

char		*apply_prefix_sign(char *str, t_flags *flags)
{
	char	*tmp;
	t_bool	positive;

	tmp = NULL;
	if (!(flags->conv_spec & CS_UNUMERIC) && flags->conv_spec & CS_NUMERIC)
	{
		positive = ft_atoi(str) > 0 ? TRUE : FALSE;
		if (positive == TRUE)
		{
			if (flags->flag_char & FC_PLUS || flags->flag_char & FC_SPACE)
				flags->visual_len += 1;
			if (flags->flag_char & FC_PLUS)
				tmp = ft_strjoin("+", str);
			else if (flags->flag_char & FC_SPACE)
				tmp = ft_strjoin(" ", str);
			tmp = ft_strdup(str);
		}
		else
			tmp = ft_strdup(str);
	}
	else
		tmp = ft_strdup(str);
	if (!tmp)
		ft_puterr_and_exit(__FILE__);
	return (tmp);
}
