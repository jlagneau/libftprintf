/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_format_percent.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:34:52 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/19 10:06:15 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		replace_format_percent(char *format, char *pos, va_list ap)
{
	char	data[2];

	(void)ap;
	ft_bzero(data, 2);
	(void)ft_strcpy(data, "%");
	return (replace_format(format, data, pos, 2));
}
