/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 09:24:31 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/22 13:59:34 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		search_format(char *str, char *pos, va_list ap)
{
	t_flags		flags;
	int			ret;

	ret = (int)ft_strlen(str);
	while (pos)
	{
		if ((pos = ft_strchr(pos, '%')))
		{
			flags.flag_length = 1;
			flags.flag_char = 0;
			flags.field_width = 0;
			flags.precision = -1;
			flags.length_mod = 0;
			ret = parse_format(str, pos, &flags, ap);
			if (ret == -1)
				return (ret);
			pos++;
		}
	}
	return (ret);
}
