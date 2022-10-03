/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shoot.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 16:33:07 by pderksen      #+#    #+#                 */
/*   Updated: 2022/09/30 15:40:29 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

float	get_rgb_color(t_vec4 color)
{
	float	result;
	float	red;
	float	green;
	float	blue;

	red = color[0] * 256 *256;
	green = color[1] * 256;
	blue = color[2];
	result = red + green + blue;
	return (result);
}

t_vec4	get_intersect_vec(t_ray *ray)
{
	t_vec4	intersect;
	t_vec4	distance;

	distance = (t_vec4){ray->t, ray->t, ray->t};
	intersect = ray->origen + (distance * ray->dir);
	return (intersect);
}

void	shoot_ray(t_ray *ray, t_data *img, t_sphere *sphere, t_plane *plane)
{
	ray->t = 0; //misschien anders
	ray->intersect_color = (t_vec4){0, 0, 0};
	sphere_intersect(ray, sphere);
	plane_intersect(ray, plane);
	if (ray->t != 0)
	{
		ray->intersect = get_intersect_vec(ray);
		//direct_light(ray, light);
		my_mlx_pixel_put(img, ray->px, ray->py, (int)get_rgb_color(ray->intersect_color));
	}
	return ;
}
