#include "../minirt.h"

double		ft_quad_solv(double a, double b, double c) //toujours des reponses positives ! et les plus petites !
{
	double	d;
	double	val1;
	double	val2;

	d = (b * b) - (4 * a * c);
	if (d < 0)
		return (0);
	val1 = (-b + sqrt(d)) / (2 * a);
	val2 = (-b - sqrt(d)) / (2 * a);
	if (val1 < 0 && val2 < 0)
		return (0);
	else if (val1 < 0)
		return (val2);
	else if (val2 < 0)
		return (val1);
	return ((val1 < val2) ? val1 : val2);
}
