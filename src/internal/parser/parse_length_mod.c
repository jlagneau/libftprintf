/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_length_mod.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 13:23:01 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/27 13:40:11 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

void		parse_length_mod(char *pos, t_flags *flags)
{
	int		i;
	t_lm	*lm;

	i = 0;
	flags->length_mod = 0;
	lm = get_length_mod();
	while (lm[i].length_mod)
	{
		if (ft_strncmp(pos + flags->flag_length, lm[i].length_mod,
			lm[i].length_mod_len) == 0)
		{
			flags->length_mod = lm[i].length_flag;
			flags->flag_length += lm[i].length_mod_len;
			break ;
		}
		i++;
	}
}
