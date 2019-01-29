/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:02:20 by apion             #+#    #+#             */
/*   Updated: 2019/01/29 19:07:49 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdarg.h>
# include "utils.h"
# include "extractor.h"

typedef struct	s_parser
{
	char	type;
	int		flag;
	int		(*f)(va_list, t_specs *, char *);
}				t_parser;

int			parse_specs(const char **f, t_specs *specs, va_list ap, char *str);

#endif
