/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/27 17:23:08 by pderksen      #+#    #+#                 */
/*   Updated: 2022/09/28 16:33:29 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

void	init_camera2(t_camera2 *cam2, t_camera *camera)
{
	t_vec4	upguide;

	upguide = (t_vec4){0, 1, 0};
	cam2->cam_cord = camera->cord;
	cam2->w = tan(((camera->fov) / 2) * ((2 * M_PI) / 360));
	cam2->h = cam2->w * ((float)S_HEIGHT / S_WIDTH);
	cam2->forward = camera->norm;
	cam2->right = get_vector_cross(cam2->forward, upguide);
	cam2->up = get_vector_cross(cam2->right, cam2->forward);
}

t_ray	get_ray_dir_and_origen(t_camera2 *cam2, int px, int py)
{
	t_vec4	dir_not_normalized;
	t_ray	ray;
	float	x;
	float	y;

	x = ((float)(2 * px) / S_WIDTH) - 1;
	y = ((float)(2 * py) / S_HEIGHT) - 1;
	ray.px = px;
	ray.py = py;
	ray.origen = cam2->cam_cord;
	dir_not_normalized = cam2->forward + (cam2->h * y * cam2->up) + (cam2->w * x * cam2->right);
	ray.dir = normalize_vector(dir_not_normalized);
	return (ray);
}

void	ray_trace(t_data *img, t_camera *camera, t_sphere *sphere)
{
	t_camera2	cam2;
	t_ray		ray;
	int 		px;
	int 		py;

	init_camera2(&cam2, camera);
	px = 0;
	py = 0;
	while (py < S_HEIGHT)
	{
		px = 0;
		while (px < S_WIDTH)
		{
			ray = get_ray_dir_and_origen(&cam2, px, py);
			shoot_ray(&ray, img, sphere);
			px++;
		}
		py++;
	}
}
