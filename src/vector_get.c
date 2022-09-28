/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_get.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pderksen <pderksen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 10:20:25 by pderksen      #+#    #+#                 */
/*   Updated: 2022/09/28 14:42:52 by pderksen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

float	get_vec_length_squared(t_vec4 vec)
{
	return (vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
}

float	get_vec_length(t_vec4 vec)
{
	return (sqrt(get_vec_length_squared(vec)));
}

float get_vector_dot(t_vec4 u, t_vec4 v)
{
	return (u[0] * v[0] + u[1] * v[1] + u[2] * v[2]);
}

t_vec4	get_vector_cross(t_vec4 u, t_vec4 v)
{
	t_vec4	cross;
	
	cross[0] = u[1] * v[2] - u[2] * v[1];
	cross[1] = u[2] * v[0] - u[0] * v[2];
	cross[2] = u[0] * v[1] - u[1] * v[0];
	return (cross);
}

t_vec4	normalize_vector(t_vec4 vec)
{
	t_vec4	uv;

	uv = vec / get_vec_length(vec);
	return (uv);
}
