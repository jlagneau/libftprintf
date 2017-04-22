/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 10:14:04 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/20 13:23:17 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static unsigned int		get_flags(unsigned int f, char fc, unsigned int v)
{
	if (fc == '-')
		f &= (unsigned int)~FC_ZERO;
	else if (fc == '+')
		f &= (unsigned int)~FC_SPACE;
	if (fc == '0' && (f & FC_MINUS))
		return (f);
	else if (fc == ' ' && (f & FC_PLUS))
		return (f);
	return (f | v);
}

void					parse_flag_char(char *pos, t_flags *flags)
{
	int					i;
	t_fc				*fc;

	i = 0;
	flags->flag_char = 0;
	fc = get_flag_character();
	while (fc[i].flag_char)
	{
		if (*(pos + flags->flag_length) == fc[i].flag_char)
		{
			flags->flag_char = get_flags(flags->flag_char, fc[i].flag_char,
										fc[i].value);
			flags->flag_length += 1;
			i = -1;
		}
		i++;
	}
}
