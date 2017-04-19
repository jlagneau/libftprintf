/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 09:42:36 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/19 12:22:38 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

t_ffs	*get_format_func(void)
{
	static t_ffs format_func_array[] = {
		{'%', replace_perc },
		{'s', replace_str },
		{'d', replace_int },
		{'D', replace_long },
		{'i', replace_int },
		{'b', replace_bin },
		{'o', replace_oct },
		{'x', replace_hex_lower },
		{'X', replace_hex_upper },
		{'c', replace_char },
		{'p', replace_ptr },
		{'u', replace_uint },
		{0, 0}
	};
	return (format_func_array);
}
