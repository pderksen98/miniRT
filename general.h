/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   general.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 11:12:41 by pderksen      #+#    #+#                 */
/*   Updated: 2022/09/29 13:24:18 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H
# include "mlx2.h"
# include "rays.h"

//camera.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	init_camera2(t_camera2 *cam2, t_camera *camera);
t_ray	get_ray_dir_and_origen(t_camera2 *cam2, int px, int py);
void	ray_trace(t_data *img, t_camera *camera, t_sphere *sphere, t_plane *plane);

//main.c
int	    main(void);
void	init_input(t_camera *camera, t_sphere *sphere, t_plane *plane);

//plane.c
void	plane_intersect(t_ray *ray, t_plane *plane);

//shoot.c
void	shoot_ray(t_ray *ray, t_data *img, t_sphere *sphere, t_plane *plane);
t_vec4	get_intersect_vec(t_ray *ray);
float	get_rgb_color(t_vec4 color);

//sphere.c
void	sphere_intersect(t_ray *ray, t_sphere *sphere);
float	get_sphere_closest_intersect(t_ray *ray, t_sphere *spere);
float	get_discriminant(t_ray *ray, t_sphere * sphere, float b);

//vector_get.c
float	get_vec_length(t_vec4 vec);
float	get_vec_length_squared(t_vec4 vec);
float	get_vector_dot(t_vec4 u, t_vec4 v);
t_vec4	get_vector_cross(t_vec4 u, t_vec4 v);
t_vec4	normalize_vector(t_vec4 vec);
#endif