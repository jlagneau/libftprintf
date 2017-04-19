/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 09:41:58 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/19 09:53:34 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

# ifdef FT_PRINTF_INTERNAL
#  include <stdarg.h>
#  define MAX_LENGTH	4096

typedef					int (*t_format_func)(char*, char*, va_list);

typedef struct			s_ffs
{
	char				flag;
	t_format_func		func;
}						t_ffs;

t_ffs					*get_format_func(void);

# endif
#endif
