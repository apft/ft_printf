/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguichar <gguichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:23:32 by gguichar          #+#    #+#             */
/*   Updated: 2018/12/06 11:30:36 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include "libunit.h"
#include "colors.h"

static int	run_single_test(t_unit_test *test)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		return (0);
	else if (pid > 0)
		wait(&status);
	else
		exit(test->fct());
	return (status);
}

static char	*str_status(int status)
{
	if (status == 0)
		return (GREEN"OK"NC);
	else if (status == SIGSEGV)
		return (RED"SEGV"NC);
	else if (status == SIGBUS)
		return (RED"BUSE"NC);
	else if (status == SIGABRT)
		return (RED"ABRT"NC);
	return ("\x1b[31mKO\x1b[0m");
}

static int	run_tests(t_unit_test *lst)
{
	int	status;
	int	working;
	int	total;

	working = 0;
	total = 0;
	while (lst != NULL)
	{
		status = run_single_test(lst);
		if (status == 0)
			working++;
		lu_putstr("> ");
		lu_putstr(lst->name);
		lu_putchar(' ');
		lu_putstr(str_status(status));
		lu_putchar('\n');
		lst = lst->next;
		total++;
	}
	lu_putnbr(working);
	lu_putchar('/');
	lu_putnbr(total);
	lu_putstr(" tests checked\n\n");
	return (total == working);
}

int			launch_tests(const char *name, t_unit_test **lst)
{
	int	res;

	res = 0;
	lu_putstr(name);
	lu_putchar('\n');
	if (lst != NULL && !run_tests(*lst))
		res = -1;
	clear_tests(lst);
	return (res);
}
