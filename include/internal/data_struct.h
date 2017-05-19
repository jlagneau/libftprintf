/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:06:01 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/27 13:29:35 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCT_H
# define DATA_STRUCT_H
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

typedef struct				s_fc
{
	char					flag_char;
	unsigned int			value;
}							t_fc;

typedef struct				s_lm
{
	char					*length_mod;
	size_t					length_mod_len;
	unsigned int			length_flag;
}							t_lm;

typedef struct				s_flags
{
	size_t					flag_length;
	unsigned int			flag_char;
	size_t					field_width;
	ssize_t					precision;
	unsigned int			length_mod;
	unsigned int			conv_spec;
	size_t					visual_len;
}							t_flags;

typedef						int (*t_format_fun)(char*, char*, t_flags, va_list);

typedef struct				s_cs
{
	char					conv_spec;
	t_format_fun			func;
	unsigned int			conv_flag;
}							t_cs;

#endif
