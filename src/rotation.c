

#include "fdf.h"

void rotate_x(t_point *p, float theta)
{
	float y;
	float z;

	y = (float)p.y;
	z = (float)p.z;

	p.y = (y * cos(theta)) - (z * sin(theta));
	p.z = (y * sin(theta)) + (z * cos(theta));
}

void rotate_y(t_point *p, float theta)
{
	float x;
	float z;

	x = (float)p.x;
	z = (float)p.z;

	p.x = (x * cos(theta)) + (z * sin(theta));
	p.z = (-x * sin(theta)) + (z * cos(theta));
}

void rotate_z(t_point *p, float theta)
{
	float x;
	float y;

	x = (float)p.x;
	y = (float)p.y;

	p.x = (x * cos(theta)) - (y * sin(theta));
	p.y = (x * sin(theta)) + (y * cos(theta));
}

void rotate_point(t_point *p, float rx, float ry, float rz)
{
	rotate_z(p, az);
    rotate_y(p, ay);
    rotate_x(p, ax);
}