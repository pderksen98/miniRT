/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plane.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 13:07:39 by pderksen      #+#    #+#                 */
/*   Updated: 2022/09/29 15:13:17 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

void	plane_intersect(t_ray *ray, t_plane *plane)
{
	float	a;
	float	b;
	float	t;

	a = get_vector_dot(ray->dir, plane->norm);
	if (a == 0)
		return ;
	b = get_vector_dot(plane->cord, plane->norm) + get_vector_dot(ray->origen, plane->norm);
	t = (1 / a) * b;
	if (t < 0 || t == 0)
		return ;
	if (ray->t == 0)
	{
		ray->t = t;
		ray->intersect_color = plane->color;
	}
	else if (t < ray->t)
	{
		ray->t = t;
		ray->intersect_color = plane->color;
	}
}