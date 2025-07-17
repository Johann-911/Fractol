/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoumani <jtoumani@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:30:44 by jtoumani          #+#    #+#             */
/*   Updated: 2025/07/16 16:24:55 by jtoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	get_color_two(double t, int mode)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	val;

	if (mode == 0)
	{
		r = (uint8_t)(200 + 55 * sin(t * 20 * M_PI));
		g = (uint8_t)(50 + 205 * pow(sin(t * 10 * M_PI), 2));
		b = (uint8_t)(255 * (0.5 + 0.5 * sin(t * 15 * M_PI)));
	}
	else if (mode == 1)
	{
		val = (uint8_t)(255 * fabs(sin(t * 30 * M_PI)));
		r = val;
		g = val;
		b = val;
	}
	else
	{
		r = (uint8_t)(100 + 105 * fabs(sin(t * 20 * M_PI)));
		g = (uint8_t)(100 + 155 * fabs(cos(t * 20 * M_PI)));
		b = 255;
	}
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

uint32_t	get_color(int iter, int max_iter, int shift, const char *name)
{
	int			mode;
	double		t;
	uint32_t	all;

	all = 0;
	if (iter >= max_iter)
		return (0x000000FF);
	mode = shift % 3;
	t = (double)iter / max_iter;
	if (ft_strncmp(name, "burning_ship", 13) == 0)
	{
		all |= ((uint32_t)(255 * pow(t, 0.7)) << 24);
		all |= ((uint32_t)(150 * t) << 16);
		return (all | 0xFF);
	}
	else
		all = get_color_two(t, mode);
	return (all);
}
