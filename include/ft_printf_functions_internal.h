/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions_internal.h                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 10:00:38 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/19 10:13:17 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FUNCTIONS_INTERNAL_H
# define FT_PRINTF_FUNCTIONS_INTERNAL_H
# ifdef FT_PRINTF_INTERNAL
# include <stdarg.h>
# include <stddef.h>
# include <ft_printf_defines_internal.h>

t_ffs	*get_format_func(void);
int		search_format(char *str, char *pos, int ret, va_list ap);
int		parse_format(char *str, char *pos, va_list ap);
int		parse_complex_format(char *str, char *pos, va_list ap);
int		replace_format(char *str, char *data, char *pos, size_t format_len);

int		replace_format_percent(char *format, char *pos, va_list ap);
int		replace_format_string(char *format, char *pos, va_list ap);
int		replace_format_integer(char *format, char *pos, va_list ap);
int		replace_format_bin(char *format, char *pos, va_list ap);
int		replace_format_oct(char *format, char *pos, va_list ap);
int		replace_format_hex_lower(char *format, char *pos, va_list ap);
int		replace_format_hex_upper(char *format, char *pos, va_list ap);
int		replace_format_char(char *format, char *pos, va_list ap);

# endif
#endif
