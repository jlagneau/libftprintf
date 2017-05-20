/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:10:41 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/27 13:34:36 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		parse_format(char *str, char *pos, t_flags *flags, va_list ap)
{
	size_t	i;
	int		ret;
	t_cs	*cs;
	t_bool	matched;

	i = 0;
	ret = 0;
	matched = FALSE;
	parse_flag_char(pos, flags);
	parse_field_width(pos, flags, ap);
	parse_precision(pos, flags, ap);
	parse_length_mod(pos, flags);
	cs = get_conv_specs();
	while (cs[i].conv_spec && matched == FALSE)
	{
		if (*(pos + flags->flag_length) == cs[i].conv_spec)
		{
			matched = TRUE;
			flags->conv_spec = cs[i].conv_flag;
			flags->flag_length += 1;
			ret = cs[i].func(str, pos, *flags, ap);
		}
		i++;
	}
	return (ret);
}
