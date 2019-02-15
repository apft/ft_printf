/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:45:29 by apion             #+#    #+#             */
/*   Updated: 2019/02/15 11:31:32 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

#include <stdio.h>
int		main(void)
{
	t_bigint	bigint;

	bigint = (t_bigint){4, {64, 32, 2347986, -1, 0}};

	t_bigint	a = (t_bigint){1, {33, 0, 0, 0, 0}};
	t_bigint	b = (t_bigint){2, {9025, 439, 0, 0, 0}};
//	print_big_int(&a);
//	print_big_int(&b);
//	t_bigint	r = (t_bigint){0};
//	bigint_add(&r, &a, &b);
//	print_big_int(&r);
//	print_big_int(&bigint);
//
//	r = (t_bigint){0};
//	bigint_add(&r, &bigint, &bigint);
//	print_big_int(&r);
//
	t_bigint	c = (t_bigint){1, {0xF0000000, 0, 0, 0, 0}};
	t_bigint	d = (t_bigint){2, {9025, 439, 0, 0, 0}};
//	printf("c=\n");
//	print_big_int(&c);
//	printf("d=\n");
//	print_big_int(&d);
	t_bigint	s = (t_bigint){0};
//	bigint_add(&s, &c, &d);
//	print_big_int(&s);
//
//	s = (t_bigint){0};
//	bigint_add(&s, &c, &c);
//	print_big_int(&s);

	s = (t_bigint){0};
	bigint_shift_left(&s, &c, 0);
	print_big_int(&s);

	s = (t_bigint){0};
	bigint_shift_left(&s, &c, 32);
	print_big_int(&s);

	s = (t_bigint){0};
	bigint_shift_left(&s, &c, 64);
	print_big_int(&s);

	s = (t_bigint){0};
	bigint_shift_left(&s, &c, 96);
	print_big_int(&s);

	s = (t_bigint){0};
	bigint_shift_left(&s, &c, 128);
	print_big_int(&s);

	s = (t_bigint){0};
	bigint_shift_left(&s, &c, 160);
	print_big_int(&s);

	bigint_shift_left_self(&c, 0);
	print_big_int(&c);

	bigint_shift_left_self(&c, 32);
	print_big_int(&c);

	bigint_shift_left_self(&c, 32);
	print_big_int(&c);

	bigint_shift_left_self(&c, 32);
	print_big_int(&c);

	bigint_shift_left_self(&c, 32);
	print_big_int(&c);

	t_bigint t = (t_bigint){0};
	bigint_shift_left(&t, &d, 4);
	print_big_int(&d);
	print_big_int(&t);

	t_bigint	e = (t_bigint){1, {0xF0000000, 0, 0, 0, 0}};
	t = (t_bigint){0};
	bigint_shift_left(&t, &e, 2);
	print_big_int(&e);
	print_big_int(&t);

	t = (t_bigint){0};
	bigint_shift_left(&t, &e, 34);
	print_big_int(&t);

	t = (t_bigint){0};
	bigint_shift_left(&t, &e, 98);
	print_big_int(&t);
	return (0);
}
