/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 09:42:36 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/18 14:16:54 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

t_format_functions g_format_functions_array[FORMAT_ARRAY_SIZE] = {
	{'%', replace_format_percent },
	{'s', replace_format_string },
	{'d', replace_format_integer },
	{'i', replace_format_integer },
	{'b', replace_format_bin },
	{'o', replace_format_oct },
	{'x', replace_format_hex_lower },
	{'X', replace_format_hex_upper },
};
