/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 20:30:24 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/23 04:12:54 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include "test.h"

void	custom(void)
{
	ft_printf("Hello World !\n");
	ft_printf("Project done at 42%% !\n");
	ft_printf("Print double percent %%%%\n");
	ft_printf("Hello %s !\n", "World");
	ft_printf("Hello %.6s !\n", (char*)NULL);
	ft_printf("Hello %i World !\n", 42);
	ft_printf("%d%d\n", 1, 23);
	ft_printf("42o = %#o\n", 42);
	ft_printf("42h = %#x\n", 42);
	ft_printf("42H = %#X\n", 42);
	ft_printf("ASCII char 42 = %c\n", 42);
	ft_printf("%c%c%c%c%c\n", 'H', 'e', 'l', 'l', 'o');
	ft_printf("%p - %p\n", "Hello World", (void*)0);
	ft_printf("%u %u\n", 2147483648, -1);
	ft_printf("Hello %s %s%s !\n", "World", "foo", "bar");
	ft_printf("Hello %10.5d%s\n", 42, "foobar");
	ft_printf("[%*.*s]\n", 10, 2, "Yolo");
	ft_printf("Print 0 with 0 precision: (%.0d)\n", 0);
	ft_printf("[%10.4S]\n", L"éàêëâäôîï");
	ft_printf("[%S] - [%S] - [%S]\n", L"中文", L"العَرَبِيَّة", L"ру́сский язы́к");
	ft_printf("[%C][%C]\n", L'中', L'文');
}