/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:20:32 by apion             #+#    #+#             */
/*   Updated: 2019/01/16 23:53:53 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		main(void)
{
	ft_printf("|%5.4d|\n", 422);
	printf("|%5.4d|\n\n", 422);
	ft_printf("|%+5.4d|\n", 422);
	printf("|%+5.4d|\n\n", 422);
	ft_printf("|%+5.4d|\n", -422);
	printf("|%+5.4d|\n\n", -422);
	ft_printf("|%+d %hhu|\n", 422, 51233545);
	printf("|%+d %hhu|\n\n", 422, 51233545);
	printf("|%05.3d|\n", 12345);
//	ft_printf("|%#10.8x|\n", 42);
//	printf("|%#10.8x|\n\n", 42);
//	ft_printf("|%#10.9x|\n", 42);
//	printf("|%#10.9x|\n\n", 42);
//	ft_printf("|%#5.0x|\n", 0);
//	printf("|%#5.0x|\n\n", 0);
//	ft_printf("|%#5x|\n", 1);
//	printf("|%#5x|\n\n", 1);
//	ft_printf("|%0#5x|\n", 1);
//	printf("|%0#5x|\n", 1);
//	printf("|%05d|\n", 1);
//	printf("|%05d|\n", -1);
//	printf("|%05.3d|\n", -1);
//	printf("|%5.5d|\n", 1);
//	printf("|%5.5d|\n", -1);
//	printf("|%5.6d|\n", 1);
//	printf("|%5.6d|\n", -1);
	return (0);
}
