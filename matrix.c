#include "ray_traycer.h"

void	rotate_matrix(t_matrix3 *matr, float alpha, float theta, float gamma)
{
	float	__sin[3];
	float	__cos[3];

	sincosf(alpha, __sin, __cos);
	sincosf(theta, __sin + 1, __cos + 1);
	(void)gamma;
	matr->a11 = __cos[0];
	matr->a12 = __sin[0] * __sin[1];
	matr->a13 = __sin[0] * __cos[1];
	matr->a21 = 0;
	matr->a22 = __cos[1];
	matr->a23 = -__sin[1];
	matr->a31 = -__sin[0];
	matr->a32 = __sin[1] * __cos[0];
	matr->a33 = __cos[0] * __cos[1];
}

void	rotate_matrix_gamma(t_matrix3 *matr, float alpha, float theta,
	float gamma)
{
	float	__sin[3];
	float	__cos[3];

	sincosf(alpha, __sin, __cos);
	sincosf(theta, __sin + 1, __cos + 1);
	sincosf(gamma, __sin + 2, __cos + 2);
	matr->a11 = __cos[2] * __cos[0];
	matr->a12 = -__sin[2] * __cos[0];
	matr->a13 = __sin[0];
	matr->a21 = __sin[1] * __sin[0] * __cos[2] + __sin[2] * __cos[1];
	matr->a22 = -__sin[1] * __sin[2] * __sin[0] + __cos[1] * __cos[2];
	matr->a23 = -__sin[1] * __cos[0];
	matr->a31 = __sin[1] * __sin[2] - __sin[0] * __cos[0] * __cos[1] * __cos[2];
	matr->a32 = __sin[1] * __cos[2] + __sin[2] * __sin[0] * __cos[1];
	matr->a33 = __cos[1] * __cos[0];
}

void	matrix3_mul(t_matrix3 *matr, t_point *vect)
{
	float	dx;
	float	dy;
	float	dz;

	dx = matr->a11 * vect->x + matr->a12 * vect->y + matr->a13 * vect->z;
	dy = matr->a21 * vect->x + matr->a22 * vect->y + matr->a23 * vect->z;
	dz = matr->a31 * vect->x + matr->a32 * vect->y + matr->a33 * vect->z;
	vect->x = dx;
	vect->y = dy;
	vect->z = dz;
}
