/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucanti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:01:56 by tlucanti          #+#    #+#             */
/*   Updated: 2021/04/20 15:33:19 by tlucanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_traycer.h"

t_color	*color(float red, float green, float blue, float intensity)
{
	t_color	*new_color;

	new_color = (t_color *) malloc (sizeof(t_color));
	if (!new_color)
		return (NULL);
	new_color->red = red * intensity;
	new_color->green = green * intensity;
	new_color->blue = blue * intensity;
	return (new_color);
}

t_color	color_stack(float red, float green, float blue, float intensity)
{
	t_color	new_color;

	new_color.red = red * intensity;
	new_color.green = green * intensity;
	new_color.blue = blue * intensity;
	return (new_color);
}
