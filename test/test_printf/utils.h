/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:28:01 by apion             #+#    #+#             */
/*   Updated: 2019/02/15 12:16:10 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <limits.h>
# include "bigint.h"

# define BUFF_SIZE 2048

void	print_diff(char *format, int length_return, int length_expected,
					char *expected, char *result, int diff);
void	print_diff_bigint(t_bigint *a, t_bigint *b, t_bigint *result,
							t_bigint *epxected, int diff);

#endif
