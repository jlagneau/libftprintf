/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_perc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:34:52 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/23 03:34:47 by jlagneau         ###   ########.fr       */
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
	flags.visual_len = 1;
	return (replace_format(format, data, pos, flags));
}
