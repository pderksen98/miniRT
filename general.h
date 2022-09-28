/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   general.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 11:12:41 by pderksen      #+#    #+#                 */
/*   Updated: 2022/09/28 14:43:29 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H
# include "mlx2.h"
# include "rays.h"

void	ray_trace(t_data *img, t_camera *camera, t_sphere *sphere);

//MLX
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	push_pixels(t_data *img);

//RAYS
float	get_vec_length(t_vec4 vec);
float	get_vec_length_squared(t_vec4 vec);
float	get_vector_dot(t_vec4 u, t_vec4 v);
t_vec4	get_vector_cross(t_vec4 u, t_vec4 v);
t_vec4	normalize_vector(t_vec4 vec);

int main(void);

#endif