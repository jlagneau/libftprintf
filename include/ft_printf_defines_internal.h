/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_defines_internal.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 09:41:58 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/19 10:04:28 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_DEFINES_INTERNAL_H
# define FT_PRINTF_DEFINES_INTERNAL_H
# ifdef FT_PRINTF_INTERNAL
#  include <stdarg.h>
#  define MAX_LENGTH	4096

typedef					int (*t_format_func)(char*, char*, va_list);

typedef struct			s_ffs
{
	char				flag;
	t_format_func		func;
}						t_ffs;

# endif
#endif
