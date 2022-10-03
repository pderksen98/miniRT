/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sphere.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 13:02:36 by pderksen      #+#    #+#                 */
/*   Updated: 2022/09/30 13:55:03 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

float	get_discriminant(t_ray *ray, t_sphere * sphere, float b)
{
	t_vec4	new_orig;
	float	a;
	float	c;
	float	D;
	float	r;

	new_orig = ray->origen - sphere->center;
	r = sphere->d / 2;
	a = 1;
	c = get_vec_length_squared(new_orig) - (r * r);
	D = (b * b) - 4 * a * c;
	return (D);
}

float	get_sphere_closest_intersect(t_ray *ray, t_sphere *sphere)
{
	t_vec4	new_orig;
	float	D;
	float	b;
	float	t;

	new_orig = ray->origen - sphere->center;
	b = 2 * (get_vector_dot(new_orig, ray->dir));
	D = get_discriminant(ray, sphere, b);
	if (D < 0)
		return (0);
	if (D == 0)
		t = -b / 2;
	else
	{
		t = (-b - sqrt(D)) / 2;
		if (t < 0)
			t = (-b + sqrt(D)) / 2;
	}
	if (t < 0)
		return (0);
	return (t);
}

void	sphere_intersect(t_ray *ray, t_sphere *sphere)
{
	float	t;

	t = get_sphere_closest_intersect(ray, sphere);
	if (t < 0 || t == 0)
		return ;
	if (ray->t == 0)
	{
		ray->t = t;
		ray->intersect_color = sphere->color;
	}
	else if (t < ray->t)
	{
		ray->t = t;
		ray->intersect_color = sphere->color;
	}
	return ;
}
