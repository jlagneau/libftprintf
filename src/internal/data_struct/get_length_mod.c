/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length_mod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 13:17:41 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/27 13:39:12 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

t_lm	*get_length_mod(void)
{
	static t_lm		length_mod_array[] = {
		{"hh", 2, LM_HH },
		{"h", 1, LM_H },
		{"ll", 2, LM_LL },
		{"l", 1, LM_L },
		{"j", 1, LM_J },
		{"z", 1, LM_Z },
		{0, 0, 0}
	};

	return (length_mod_array);
}
