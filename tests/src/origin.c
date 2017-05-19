/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   origin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 20:30:24 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/27 12:40:00 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdio.h>
#include "test.h"

void	origin(void)
{
	size_t	ret;

	ret = printf("Hello World !\n");
	ret += printf("Project done at 42%% !\n");
	ret += printf("Print double percent %%%%\n");
	ret += printf("Hello %s !\n", "World");
	ret += printf("Hello %.6s !\n", (char*)NULL);
	ret += printf("Hello %i World !\n", 42);
	ret += printf("%d%d\n", 1, 23);
	ret += printf("42o = %#o\n", 42);
	ret += printf("42h = %#x\n", 42);
	ret += printf("42H = %#X\n", 42);
	ret += printf("ASCII char 42 = %c\n", 42);
	ret += printf("%c%c%c%c%c\n", 'H', 'e', 'l', 'l', 'o');
	ret += printf("%p - %p\n", (void*)-1, (void*)0);
	ret += printf("%u %u\n", (unsigned int)2147483648, (unsigned int)-1);
	ret += printf("Hello %s %s%s !\n", "World", "foo", "bar");
	ret += printf("Hello %10.5d%s\n", 42, "foobar");
	ret += printf("[%*.*s]\n", 10, 2, "Yolo");
	ret += printf("Print 0 with 0 precision: (%.0d)\n", 0);
	ret += printf("[%10.4ls]\n", L"éàêëâäôîï");
	ret += printf("[%ls] - [%ls] - [%ls]\n", L"中文", L"العَرَبِيَّة", L"ру́сский язы́к");
	ret += printf("[%lc][%lc]\n", L'中', L'文');
	printf("ret = %zu\n", ret);
}
