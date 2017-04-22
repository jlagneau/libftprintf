/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_perc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:34:52 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/20 18:48:18 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		replace_perc(char *format, char *pos, t_flags flags, va_list ap)
{
	char	data[2];

	(void)ap;
	ft_bzero(data, 2);
	(void)ft_strcpy(data, "%");
	return (replace_format(format, data, pos, flags));
}
