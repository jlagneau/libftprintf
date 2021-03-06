/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 10:00:38 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/27 13:39:43 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include <stdarg.h>
# include <stddef.h>

t_cs	*get_conv_specs(void);
t_fc	*get_flag_character(void);
t_lm	*get_length_mod(void);

int		search_format(char *str, char *pos, va_list ap);
int		parse_format(char *str, char *pos, t_flags *flags, va_list ap);

void	parse_flag_char(char *pos, t_flags *flags);
void	parse_field_width(char *pos, t_flags *flags, va_list ap);
void	parse_precision(char *pos, t_flags *flags, va_list ap);
void	parse_length_mod(char *pos, t_flags *flags);

char	*precision(char *str, t_flags *flags);
char	*prepend_zeroes(char *str, size_t len);
char	*format_data(char *str, char *prefix, t_flags *flags);
char	*apply_precision(char *str, t_flags *flags);
char	*apply_zero_padding(char *str, t_flags *flags);
char	*apply_prefix_sign(char *str, t_flags *flags);
char	*apply_prefix(char *str, char *prefix, t_flags *flags);
char	*apply_padding(char *str, t_flags *flags);

int		replace_format(char *str, char *data, char *pos, t_flags flags);

int		replace_perc(char *format, char *pos, t_flags flags, va_list ap);
int		replace_char(char *format, char *pos, t_flags flags, va_list ap);
int		replace_wint(char *format, char *pos, t_flags flags, va_list ap);
int		replace_str(char *format, char *pos, t_flags flags, va_list ap);
int		replace_wchar(char *format, char *pos, t_flags flags, va_list ap);
int		replace_int(char *format, char *pos, t_flags flags, va_list ap);
int		replace_uint(char *format, char *pos, t_flags flags, va_list ap);
int		replace_long(char *format, char *pos, t_flags flags, va_list ap);
int		replace_ulong(char *format, char *pos, t_flags flags, va_list ap);
int		replace_bin(char *format, char *pos, t_flags flags, va_list ap);
int		replace_oct(char *format, char *pos, t_flags flags, va_list ap);
int		replace_hex_lower(char *format, char *pos, t_flags flags, va_list ap);
int		replace_hex_upper(char *format, char *pos, t_flags flags, va_list ap);
int		replace_ptr(char *format, char *pos, t_flags flags, va_list ap);

#endif
