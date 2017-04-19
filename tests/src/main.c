/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 20:30:24 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/19 10:34:16 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include "test.h"

int		main(void)
{
	ft_printf("Hello World !\n");
	ft_printf("Project done at 42%% !\n");
	ft_printf("Print double percent %%%%\n");
	ft_printf("Hello %s !\n", "World");
	ft_printf("Hello %d World !\n", 42);
	ft_printf("Hello %i World !\n", 42);
	ft_printf("%d%d\n", 1, 23);
	ft_printf("42b = %b\n", 42);
	ft_printf("42o = %o\n", 42);
	ft_printf("42h = %x\n", 42);
	ft_printf("42H = %X\n", 42);
	ft_printf("ASCII char 42 = %c\n", 42);
	ft_printf("%c%c%c%c%c\n", 'H', 'e', 'l', 'l', 'o');
	ft_printf("%p - %p\n", "Hello World", (void*)0);
	ft_printf("Hello %s %s%s !\n", "World", "foo", "bar");
	ft_printf("Hello %d%s%b\n", 42, "foobar", 5);
	return (0);
}
