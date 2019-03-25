/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:48:58 by apion             #+#    #+#             */
/*   Updated: 2019/03/25 17:23:47 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"
#include "color.h"
#include "handlers.h"

int		clear_screen(va_list ap, t_specs *specs, char *str)
{
	(void)ap;
	return (handle_str_conv(CLEAR_SCREEN, specs, str));
}
