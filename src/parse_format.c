/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:10:41 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/19 09:54:18 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		parse_format(char *str, char *pos, va_list ap)
{
	size_t	i;
	int		ret;
	t_ffs	*ffp;

	i = 0;
	ret = 0;
	ffp = get_format_func();
	while (ffp[i].flag)
	{
		if (*(pos + 1) == ffp[i].flag)
		{
			ret = ffp[i].func(str, pos, ap);
			break ;
		}
		if (ret == -1)
			return (ret);
		i++;
	}
	return (ret);
}
