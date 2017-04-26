/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   origin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 20:30:24 by jlagneau          #+#    #+#             */
/*   Updated: 2017/04/26 21:43:51 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdio.h>
#include "test.h"

void	origin(void)
{
	printf("Hello World !\n");
	printf("Project done at 42%% !\n");
	printf("Print double percent %%%%\n");
	printf("Hello %s !\n", "World");
	printf("Hello %.6s !\n", (char*)NULL);
	printf("Hello %i World !\n", 42);
	printf("%d%d\n", 1, 23);
	printf("42o = %#o\n", 42);
	printf("42h = %#x\n", 42);
	printf("42H = %#X\n", 42);
	printf("ASCII char 42 = %c\n", 42);
	printf("%c%c%c%c%c\n", 'H', 'e', 'l', 'l', 'o');
	printf("%p - %p\n", (void*)-1, (void*)0);
	printf("%u %u\n", (unsigned int)2147483648, (unsigned int)-1);
	printf("Hello %s %s%s !\n", "World", "foo", "bar");
	printf("Hello %10.5d%s\n", 42, "foobar");
	printf("[%*.*s]\n", 10, 2, "Yolo");
	printf("Print 0 with 0 precision: (%.0d)\n", 0);
	printf("[%10.4ls]\n", L"éàêëâäôîï");
	printf("[%ls] - [%ls] - [%ls]\n", L"中文", L"العَرَبِيَّة", L"ру́сский язы́к");
	printf("[%lc][%lc]\n", L'中', L'文');
}
