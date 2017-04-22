/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_defines_internal.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 09:41:58 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/21 17:15:46 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_DEFINES_INTERNAL_H
# define FT_PRINTF_DEFINES_INTERNAL_H
# ifdef FT_PRINTF_INTERNAL
#  include <stddef.h>
#  include <unistd.h>
#  include <stdarg.h>
#  define MAX_LENGTH	8192

/*
** Character flags
**
**  16 |  8 |  4 |  2 |  1
** spc |  + |  - |  0 |  #
*/
#  define FC_SHARP      0x01
#  define FC_ZERO       0x02
#  define FC_MINUS		0x04
#  define FC_PLUS		0x08
#  define FC_SPACE		0x10

/*
** Length modifier flags
**
**  32 | 16 |  8 |  4 |  2 |  1
**   z |  j | ll |  l | hh |  h
*/
#  define LM_H          0x01
#  define LM_HH			0x02
#  define LM_L			0x04
#  define LM_LL			0x08
#  define LM_J			0x10
#  define LM_Z			0x20

/*
** Converter specifier flags
*/
#  define CS_NUMERIC	0x01
#  define CS_UNUMERIC	0x02
#  define CS_SPECIAL	0x04
#  define CS_CHAR		0x08

typedef struct			s_fc
{
	char				flag_char;
	unsigned int		value;
}						t_fc;

typedef struct			s_flags
{
	size_t				flag_length;
	unsigned int		flag_char;
	size_t				field_width;
	ssize_t				precision;
	unsigned int		length_mod;
	unsigned int		conv_spec;
}						t_flags;

typedef					int (*t_format_func)(char*, char*, t_flags, va_list);

typedef struct			s_cs
{
	char				conv_spec;
	t_format_func		func;
	unsigned int		conv_flag;
}						t_cs;

# endif
#endif
