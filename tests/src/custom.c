/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 20:30:24 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/27 13:01:23 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include "test.h"

/*
static size_t	simple_conv(void)
{
	size_t	ret;

	ret = ft_printf("Hello World !\n");
	ret += ft_printf("Project done at 42%% !\n");
	ret += ft_printf("Hello %s %s !\n", "World", (char*)NULL);
	ret += ft_printf("[%S] - [%S] - [%S] - [%S]\n",
		L"éàêëâäôîï", L"中文", L"العَرَبِيَّة", L"ру́сский язы́к");
	ret += ft_printf("%p - %p\n", (void*)-1, (void*)0);
	ret += ft_printf("%d%d\n", 1, 23);
	ret += ft_printf("Hello %i World !\n", 42);
	ret += ft_printf("42o = %#o\n", 42);
	ret += ft_printf("42h = %#x\n", 42);
	ret += ft_printf("42H = %#X\n", 42);
	ret += ft_printf("ASCII char 42 = %c\n", 42);
	ret += ft_printf("%u %u\n", 2147483648, -1);
	ret += ft_printf("[%C][%C]\n", L'中', L'文');
	return (ret);
}
*/

void	custom(void)
{
	size_t	ret;

	ret = ft_printf("Hello World !\n");
	ret += ft_printf("Project done at 42%% !\n");
	ret += ft_printf("Print double percent %%%%\n");
	ret += ft_printf("Hello %s !\n", "World");
	ret += ft_printf("Hello %.6s !\n", (char*)NULL);
	ret += ft_printf("Hello %i World !\n", 42);
	ret += ft_printf("%d%d\n", 1, 23);
	ret += ft_printf("42o = %#o\n", 42);
	ret += ft_printf("42h = %#x\n", 42);
	ret += ft_printf("42H = %#X\n", 42);
	ret += ft_printf("ASCII char 42 = %c\n", 42);
	ret += ft_printf("%c%c%c%c%c\n", 'H', 'e', 'l', 'l', 'o');
	ret += ft_printf("%p - %p\n", (void*)-1, (void*)0);
	ret += ft_printf("%u %u\n", 2147483648, -1);
	ret += ft_printf("Hello %s %s%s !\n", "World", "foo", "bar");
	ret += ft_printf("Hello %10.5d%s\n", 42, "foobar");
	ret += ft_printf("[%*.*s]\n", 10, 2, "Yolo");
	ret += ft_printf("Print 0 with 0 precision: (%.0d)\n", 0);
	ret += ft_printf("[%10.4S]\n", L"éàêëâäôîï");
	ret += ft_printf("[%S] - [%S] - [%S]\n", L"中文", L"العَرَبِيَّة", L"ру́сский язы́к");
	ret += ft_printf("[%C][%C]\n", L'中', L'文');
	ft_printf("ret = %u\n", ret);
}
