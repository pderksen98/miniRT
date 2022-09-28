/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shoot.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 16:33:07 by pderksen      #+#    #+#                 */
/*   Updated: 2022/09/28 16:34:07 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

int	intersect(t_ray *ray, t_sphere *sphere)
{
	
}

void	shoot_ray(t_ray *ray, t_data *img, t_sphere *sphere)
{
	if (intersect(ray, sphere))
	{
		my_mlx_pixel_put(img, ray->px, ray->py, (int)ray->color);
	}
}
