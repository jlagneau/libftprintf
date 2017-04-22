/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 10:03:45 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/22 10:05:30 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

char		*apply_precision(char *str, t_flags flags)
{
	char	*tmp;

	tmp = NULL;
	if (flags.precision >= 0)
		tmp = precision(str, flags);
	else
	{
		if (!(tmp = ft_strdup(str)))
			ft_puterr_and_exit(__FILE__);
	}
	return (tmp);
}
