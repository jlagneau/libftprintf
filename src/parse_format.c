/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:10:41 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/19 10:12:30 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		parse_format(char *str, char *pos, va_list ap)
{
	size_t	i;
	int		ret;
	t_ffs	*ffp;
	t_bool	matched;

	i = 0;
	ret = 0;
	matched = FALSE;
	ffp = get_format_func();
	while (ffp[i].flag)
	{
		if (*(pos + 1) == ffp[i].flag)
		{
			matched = TRUE;
			ret = ffp[i].func(str, pos, ap);
			break ;
		}
		i++;
	}
	if (matched == FALSE)
		ret = parse_complex_format(str, pos, ap);
	return (ret);
}
