/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_prefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 10:06:37 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/22 10:07:18 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

char		*apply_prefix(char *str, char *prefix, t_flags flags)
{
	char	*tmp;
	size_t	len;

	tmp = NULL;
	len = ft_strlen(str);
	if (flags.flag_char & FC_SHARP && flags.conv_spec & CS_SPECIAL && len > 0)
		tmp = ft_strjoin(prefix, str);
	else
		tmp = ft_strdup(str);
	if (!tmp)
		ft_puterr_and_exit(__FILE__);
	return (tmp);
}
