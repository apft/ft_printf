/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 13:20:31 by apion             #+#    #+#             */
/*   Updated: 2018/12/06 11:30:47 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	add_test(t_unit_test **head, char *name, int (*fct)(void))
{
	t_unit_test	*node;
	t_unit_test	*current;

	if (!head)
		return ;
	node = (t_unit_test *)malloc(sizeof(*node));
	if (!node)
		return ;
	node->name = name;
	node->fct = fct;
	node->next = NULL;
	if (!*head)
	{
		*head = node;
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = node;
}

void	clear_tests(t_unit_test **head)
{
	t_unit_test	*current;
	t_unit_test	*tmp;

	if (!head || !*head)
		return ;
	current = *head;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*head = 0;
}
