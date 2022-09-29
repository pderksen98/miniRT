/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rays.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 10:09:57 by pderksen      #+#    #+#                 */
/*   Updated: 2022/09/29 14:46:12 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H
# include "mlx2.h"

typedef float	t_vec4 __attribute__ ((vector_size (16)));

typedef struct s_ray
{
	t_vec4	origen;
	t_vec4	dir;
	int		px;
	int		py;
	float	t; //smallest intersect
	t_vec4	intersect;
	t_vec4	intersect_color;
	t_vec4	pixel_color;
}	t_ray;

typedef struct s_camera2
{
	float	h;
	float	w;
	t_vec4	cam_cord;
	t_vec4	forward;
	t_vec4	up;
	t_vec4	right;
}	t_camera2;



typedef struct	s_camera {
	t_vec4	cord;
	t_vec4	norm;
	float	fov;
}	t_camera;

typedef struct	s_plane {
	t_vec4	cord;
	t_vec4	norm;
	t_vec4	color;
}	t_plane;

typedef struct	s_sphere {
	t_vec4	center;
	t_vec4	color;
	float	d;
}	t_sphere;

typedef struct	s_parser
{
	t_camera	cam;
	t_sphere	*sphere;
	t_plane		*plane;
}	t_parser;
#endif