/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 18:24:10 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/19 10:05:05 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

# ifdef FT_PRINTF_INTERNAL
#  include <ft_printf_functions_internal.h>
# endif

int		ft_printf(char const *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_sprintf(char *str, const char *format, ...);
int		ft_vprintf(char const *format, va_list ap);
int		ft_vdprintf(int fd, const char *format, va_list ap);
int		ft_vsprintf(char *str, const char *format, va_list ap);

#endif
