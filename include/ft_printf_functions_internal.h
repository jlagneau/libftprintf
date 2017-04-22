/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions_internal.h                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 10:00:38 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/22 10:13:30 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FUNCTIONS_INTERNAL_H
# define FT_PRINTF_FUNCTIONS_INTERNAL_H
# ifdef FT_PRINTF_INTERNAL
# include <stdarg.h>
# include <stddef.h>
# include <ft_printf_defines_internal.h>

t_cs	*get_conv_specs(void);
t_fc	*get_flag_character(void);

int		search_format(char *str, char *pos, int ret, va_list ap);
int		parse_format(char *str, char *pos, t_flags *flags, va_list ap);

void	parse_flag_char(char *pos, t_flags *flags);
void	parse_field_width(char *pos, t_flags *flags, va_list ap);
void	parse_precision(char *pos, t_flags *flags, va_list ap);

char	*precision(char *str, t_flags flags);
char	*prepend_zeroes(char *str, size_t len);
char	*format_data(char *str, char *prefix, t_flags flags);
char	*apply_precision(char *str, t_flags flags);
char	*apply_zero_padding(char *str, t_flags flags);
char	*apply_prefix_sign(char *str, t_flags flags);
char	*apply_prefix(char *str, char *prefix, t_flags flags);
char	*apply_padding(char *str, t_flags flags);

int		replace_format(char *str, char *data, char *pos, t_flags flags);

int		replace_perc(char *format, char *pos, t_flags flags, va_list ap);
int		replace_char(char *format, char *pos, t_flags flags, va_list ap);
int		replace_str(char *format, char *pos, t_flags flags, va_list ap);
int		replace_int(char *format, char *pos, t_flags flags, va_list ap);
int		replace_uint(char *format, char *pos, t_flags flags, va_list ap);
int		replace_long(char *format, char *pos, t_flags flags, va_list ap);
int		replace_bin(char *format, char *pos, t_flags flags, va_list ap);
int		replace_oct(char *format, char *pos, t_flags flags, va_list ap);
int		replace_hex_lower(char *format, char *pos, t_flags flags, va_list ap);
int		replace_hex_upper(char *format, char *pos, t_flags flags, va_list ap);
int		replace_ptr(char *format, char *pos, t_flags flags, va_list ap);

# endif
#endif
