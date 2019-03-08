#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "utils.h"

int		test_float_conv(void)
{
	int		error;
	char	*format;
	char	str_printf[BUFF_SIZE];
	char	*out;
	int		ret;
	int		ret_exp;
	int		diff;
	double		n;

	bzero(str_printf, BUFF_SIZE);
	//format = "|%f|%10f|%10.f|%10.0f|%.1f|%10.2f|%10.5f|";
	format = "|%f|%f|%f|";
	n = 4.423547891112;
	double p = 0.000000343549217;
	double q = 34354.9217;
	ret_exp = sprintf(str_printf, format, n, p, q, n, n, n, n);
	ret = ft_asprintf(&out, format, n, p, q, n, n, n, n);

	diff = strcmp(out, str_printf);
	error = ret != ret_exp || diff;
	if (error)
		print_diff(format, ret, ret_exp, str_printf, out, diff);
	free(out);
	return (error);
}
