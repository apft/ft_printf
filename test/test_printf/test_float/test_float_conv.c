#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
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
	format = "|%.50f|%.75f|%51.40f|%f|%.50f|\n";
//	format = "|%f|";
	n = 4.423547891112;
	double p = 0.000000343549217;
	double q = 34354.9217;
	double max = DBL_MAX;
	double r = 0x1.0254p+0;
	printf("%s", format);
	ret_exp = sprintf(str_printf, format, n, p, q, max, r, n, n);
	ret = ft_asprintf(&out, format, n, p, q, max, r, n, n);
//	format = "|%f|%10f|%10.f|%10.0f|%.1f|%10.2f|%10.5f|\n";
//	printf("%s", format);
//	printf(format, max, max, max, max, max, max, max, max);
//	printf(format, p, p, p, p, p, p, p, p);
//	printf(format, q, q, q, q, q, q, q, q);

	diff = strcmp(out, str_printf);
	error = ret != ret_exp || diff;
	if (error)
		print_diff(format, ret, ret_exp, str_printf, out, diff);
	free(out);
	return (error);
}
