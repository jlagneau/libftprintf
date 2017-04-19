/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_format_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 10:28:27 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/19 10:32:52 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

int		replace_format_ptr(char *format, char *pos, va_list ap)
{
	int		ret;
	char	*tmp;
	char	*data;

	tmp = NULL;
	if (!(tmp = ft_itoa_base(va_arg(ap, unsigned int), BASE_HEX_LOWER)))
		return (-1);
	if (ft_strcmp(tmp, "0") == 0)
		data = ft_strdup("(nil)");
	else
		data = ft_strjoin("0x", tmp);
	ret = replace_format(format, data, pos, 2);
	ft_strdel(&data);
	ft_strdel(&tmp);
	return (ret);
}
