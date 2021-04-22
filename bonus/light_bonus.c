/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:01:21 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:33:41 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

int	light(t_light_input *inp, t_light **dest)
{
	t_light	*new_light;

	*dest = NULL;
	new_light = (t_light *) malloc (sizeof(t_light));
	if (!new_light)
		return (ft_free(inp->rgb) + ft_free(inp->vect) + 1);
	new_light->type = inp->type;
	new_light->color = inp->rgb;
	new_light->vect = inp->vect;
	if (inp->type == 'd')
		normalize(inp->vect);
	*dest = new_light;
	return (0);
}
