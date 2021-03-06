/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conv_spec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 09:42:36 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/26 22:08:46 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

t_cs	*get_conv_specs(void)
{
	static t_cs		conv_specs_array[] = {
		{'%', replace_perc, 0 },
		{'c', replace_char, CS_CHAR },
		{'C', replace_wint, CS_CHAR | CS_WCHAR },
		{'s', replace_str, CS_CHAR },
		{'S', replace_wchar, CS_CHAR | CS_WCHAR },
		{'d', replace_int, CS_NUMERIC },
		{'i', replace_int, CS_NUMERIC },
		{'u', replace_uint, CS_NUMERIC | CS_UNUMERIC },
		{'U', replace_ulong, CS_NUMERIC | CS_UNUMERIC },
		{'D', replace_long, CS_NUMERIC },
		{'b', replace_bin, CS_NUMERIC | CS_UNUMERIC | CS_SPECIAL },
		{'o', replace_oct, CS_NUMERIC | CS_UNUMERIC | CS_SPECIAL },
		{'O', replace_oct, CS_NUMERIC | CS_UNUMERIC | CS_SPECIAL },
		{'x', replace_hex_lower, CS_NUMERIC | CS_UNUMERIC | CS_SPECIAL },
		{'X', replace_hex_upper, CS_NUMERIC | CS_UNUMERIC | CS_SPECIAL },
		{'p', replace_ptr, CS_NUMERIC | CS_UNUMERIC | CS_SPECIAL },
		{0, 0, 0}
	};

	return (conv_specs_array);
}
