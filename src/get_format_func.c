/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 09:42:36 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/19 10:44:09 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

t_ffs	*get_format_func(void)
{
	static t_ffs format_func_array[] = {
		{'%', replace_format_percent },
		{'s', replace_format_string },
		{'d', replace_format_integer },
		{'i', replace_format_integer },
		{'b', replace_format_bin },
		{'o', replace_format_oct },
		{'x', replace_format_hex_lower },
		{'X', replace_format_hex_upper },
		{'c', replace_format_char },
		{'p', replace_format_ptr },
		{'u', replace_format_unsigned },
		{0, 0}
	};
	return (format_func_array);
}
