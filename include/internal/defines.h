/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 09:41:58 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/26 15:07:05 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define FT_PRINTF_MAX_LEN	8192

/*
** Character flags
**
**  16 |  8 |  4 |  2 |  1
** spc |  + |  - |  0 |  #
*/
# define FC_SHARP			0x01
# define FC_ZERO			0x02
# define FC_MINUS			0x04
# define FC_PLUS			0x08
# define FC_SPACE			0x10

/*
** Length modifier flags
**
**  32 | 16 |  8 |  4 |  2 |  1
**   z |  j | ll |  l | hh |  h
*/
# define LM_H				0x01
# define LM_HH				0x02
# define LM_L				0x04
# define LM_LL				0x08
# define LM_J				0x10
# define LM_Z				0x20

/*
** Converter specifier flags
*/
# define CS_NUMERIC			0x01
# define CS_UNUMERIC		0x02
# define CS_SPECIAL			0x04
# define CS_CHAR			0x08
# define CS_WCHAR			0x10

#endif
