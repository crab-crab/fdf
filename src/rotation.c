

#include "fdf.h"

void rotate_x(t_point *p, float theta)
{
	float y;
	float z;

	y = p->y;
	z = p->z;

	p->y = (y * cos(theta)) - (z * sin(theta));
	p->z = (y * sin(theta)) + (z * cos(theta));
}

void rotate_y(t_point *p, float theta)
{
	float x;
	float z;

	x = p->x;
	z = p->z;

	p->x = (x * cos(theta)) + (z * sin(theta));
	p->z = (-x * sin(theta)) + (z * cos(theta));
}

void rotate_z(t_point *p, float theta)
{
	float x;
	float y;

	x = p->x;
	y = p->y;

	p->x = (x * cos(theta)) - (y * sin(theta));
	p->y = (x * sin(theta)) + (y * cos(theta));
}

void rotate_point(t_point *p, float rx, float ry, float rz)
{
	// rotate_z(p, rz);
	// rotate_y(p, ry);
	rotate_x(p, rx);
    rotate_y(p, ry);
	rotate_z(p, rz);
}

