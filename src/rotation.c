

#include "fdf.h"

// void rotate_x(t_point *p, float theta)
// {
// 	float y;
// 	float z;

// 	y = p->y;
// 	z = p->z;

// 	p->y = (y * cos(theta)) - (z * sin_t);
// 	p->z = (y * sin_t) + (z * cos(theta));
// }

// void rotate_y(t_point *p, float theta)
// {
// 	float x;
// 	float z;

// 	x = p->x;
// 	z = p->z;

// 	p->x = (x * cos(theta)) + (z * sin_t);
// 	p->z = (-x * sin_t) + (z * cos(theta));
// }

// void rotate_z(t_point *p, float theta)
// {
// 	float x;
// 	float y;

// 	x = p->x;
// 	y = p->y;

// 	p->x = (x * cos(theta)) - (y * sin_t);
// 	p->y = (x * sin_t) + (y * cos(theta));
// }

// void rotate_point(t_point *p, float rx, float ry, float rz)
// {
// 	// rotate_z(p, rz);
// 	// rotate_y(p, ry);
// 	rotate_x(p, rx);
//     rotate_y(p, ry);
// 	rotate_z(p, rz);
// }

void rotate_x_n(t_node *node, float cos_t, float sin_t)
{
	float y;
	float z;

	y = node->y;
	z = node->z;

	node->y = (y * cos_t) - (z * sin_t);
	node->z = (y * sin_t) + (z * cos_t);
}

void rotate_y_n(t_node *node, float cos_t, float sin_t)
{
	float x;
	float z;

	x = node->x;
	z = node->z;

	node->x = (x * cos_t) + (z * sin_t);
	node->z = (-x * sin_t) + (z * cos_t);
}

void rotate_z_n(t_node *node, float cos_t, float sin_t)
{
	float x;
	float y;

	x = node->x;
	y = node->y;

	node->x = (x * cos_t) - (y * sin_t);
	node->y = (x * sin_t) + (y * cos_t);
}

void rotate_node(t_node *node, t_display *display)
{
	// rotate_z(p, rz);
	// rotate_y(p, ry);
	rotate_x_n(node, display->cos_rx, display->sin_rx);
    rotate_y_n(node, display->cos_ry, display->sin_ry);
	rotate_z_n(node, display->cos_rz, display->sin_rz);
}

