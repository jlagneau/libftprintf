/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepend_zeroes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 14:16:35 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/21 15:29:00 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

char		*prepend_zeroes(char *str, size_t len)
{
	char	*tmp;
	char	*data;

	tmp = NULL;
	data = NULL;
	if (!(tmp = ft_strnew(len)))
		ft_puterr_and_exit(__FILE__);
	tmp = ft_memset(tmp, '0', len);
	if (!(data = ft_strjoin(tmp, str)))
		ft_puterr_and_exit(__FILE__);
	ft_strdel(&tmp);
	return (data);
}
