/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flag_character.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 19:44:34 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/22 14:42:40 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

t_fc	*get_flag_character(void)
{
	static t_fc		flag_char_array[] = {
		{'#', FC_SHARP },
		{'0', FC_ZERO },
		{'-', FC_MINUS },
		{' ', FC_SPACE },
		{'+', FC_PLUS },
		{0, 0}
	};

	return (flag_char_array);
}
