/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:10:41 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/18 13:18:27 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		parse_format(char *str, char *pos, va_list ap)
{
	size_t	i;
	int		ret;

	i = 0;
	ret = 0;
	while (i < FORMAT_ARRAY_SIZE)
	{
		if (*(pos + 1) == g_format_functions_array[i].flag)
		{
			ret = g_format_functions_array[i].func(str, pos, ap);
			break ;
		}
		if (ret == -1)
			return (ret);
		i++;
	}
	return (ret);
}
