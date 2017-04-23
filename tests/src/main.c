/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 20:30:24 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/23 04:12:54 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include <locale.h>
#include "test.h"

static void	print_usage(void)
{
	ft_dprintf(STDERR, "Usage: ./test (origin|custom)\n");
}

int		main(int argc, char *argv[])
{
	setlocale(LC_CTYPE, "");
	if (argc != 2)
	{
		print_usage();
		return (1);
	}
	if (ft_strcmp(argv[1], "origin") == 0)
		origin();
	else if (ft_strcmp(argv[1], "custom") == 0)
		custom();
	else
	{
		print_usage();
		return (1);
	}	
	return (0);
}
