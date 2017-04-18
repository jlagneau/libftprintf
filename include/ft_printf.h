/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 18:24:10 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/18 14:28:17 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

# ifdef FT_PRINTF_INTERNAL
# include <libft.h>
# include <ft_printf_internal.h>

int		parse_format(char *str, char *pos, va_list ap);
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

int		ft_printf(char const *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_sprintf(char *str, const char *format, ...);
int		ft_vprintf(char const *format, va_list ap);
int		ft_vdprintf(int fd, const char *format, va_list ap);
int		ft_vsprintf(char *str, const char *format, va_list ap);

#endif
