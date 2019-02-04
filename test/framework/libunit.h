/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 13:06:49 by apion             #+#    #+#             */
/*   Updated: 2018/12/06 10:59:50 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_TEST_H
# define UNIT_TEST_H

# include <stdlib.h>

typedef struct	s_unit_test
{
	char				*name;
	int					(*fct)(void);
	struct s_unit_test	*next;
}				t_unit_test;

void			add_test(t_unit_test **head, char *name, int (*fct)(void));
void			clear_tests(t_unit_test **head);
int				launch_tests(const char *name, t_unit_test **list);

void			lu_putchar(char c);
void			lu_putstr(const char *str);
void			lu_putnbr(int nb);

#endif
