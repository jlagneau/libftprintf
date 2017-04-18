/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 09:41:58 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/18 10:32:02 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

# ifdef FT_PRINTF_INTERNAL
#  include <stdarg.h>
#  define FORMAT_ARRAY_SIZE	6
#  define MAX_LENGTH		4096

typedef						int (*format_func)(char*, char*, va_list);

typedef struct				s_format_functions
{
	char					flag;
	format_func				func;
}							t_format_functions;

extern t_format_functions	g_format_functions_array[FORMAT_ARRAY_SIZE];

# endif
#endif
