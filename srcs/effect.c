/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:48:58 by apion             #+#    #+#             */
/*   Updated: 2019/03/25 18:41:56 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "utils.h"
#include "effect.h"
#include "handlers.h"

t_effect		g_effect[] =
{
	{"reset", RESET},
	{"eoc", RESET},
	{"nc", RESET},
	{"", RESET},
	{"bold", BOLD},
	{"dim", DIM},
	{"itatic", ITALIC},
	{"underline", UNDERLINE},
	{"reverse", REVERSE_VIDEO},
	{"crossed", CROSSED},
	{"strike", CROSSED},
	{"black", BLACK},
	{"red", RED},
	{"green", GREEN},
	{"yellow", YELLOW},
	{"blue", BLUE},
	{"magenta", MAGENTA},
	{"cyan", CYAN},
	{"white", WHITE},
	{"black_bg", BLACK_BG},
	{"red_bg", RED_BG},
	{"green_bg", GREEN_BG},
	{"yellow_bg", YELLOW_BG},
	{"blue_bg", BLUE_BG},
	{"magenta_bg", MAGENTA_BG},
	{"cyan_bg", CYAN_BG},
	{"white_bg", WHITE_BG},
	{"light_black", LIGHT_BLACK},
	{"light_red", LIGHT_RED},
	{"light_green", LIGHT_GREEN},
	{"light_yellow", LIGHT_YELLOW},
	{"light_blue", LIGHT_BLUE},
	{"light_magenta", LIGHT_MAGENTA},
	{"light_cyan", LIGHT_CYAN},
	{"light_white", LIGHT_WHITE}
};

static int	effect_match(const char **effect, char *expected)
{
	int		i;

	i = 1;
	if (!effect || !*effect || !expected)
		return (0);
	while (*(*effect + i) != '}' && *expected && *(*effect + i) == *expected++)
		++i;
	if (*(*effect + i) == '}' && !*expected)
	{
		*effect += i;
		return (1);
	}
	return (0);
}

int			apply_effect(const char **effect, t_specs *specs, char *str)
{
	int		size;
	int		i;

	specs->flags ^= STRING;
	size = sizeof(g_effect) / sizeof(t_effect);
	i = 0;
	while (i < size)
	{
		if (effect_match(effect, g_effect[i].effect))
			return (handle_str_conv(g_effect[i].sgr, specs, str));
		++i;
	}
	specs->flags ^= STRING | CHAR;
	return (handle_char_conv('{', specs, str));
}

int			clear_screen(va_list ap, t_specs *specs, char *str)
{
	(void)ap;
	return (handle_str_conv(CLEAR_SCREEN, specs, str));
}
