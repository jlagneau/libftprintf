/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 09:24:31 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/19 09:26:07 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		search_format(char *str, char *pos, int ret, va_list ap)
{
	while (pos)
	{
		if ((pos = ft_strchr(pos, '%')))
		{
			ret = parse_format(str, pos, ap);
			pos++;
		}
	}
	return (ret);
}
