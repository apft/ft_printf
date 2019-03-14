/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_float.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 11:26:42 by apion             #+#    #+#             */
/*   Updated: 2019/03/14 09:04:54 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FLOAT_H
# define FILLER_FLOAT_H

# include "utils.h"
# include "float_pf.h"

int		fill_float_pref_radix(union u_double *v, char *str, t_specs *specs);
int		fill_float_exp(union u_double *v, char *str, t_specs *specs);
void	fill_float(union u_double *v, char *b, char *str, t_specs *specs);

#endif
