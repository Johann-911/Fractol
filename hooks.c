/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoumani <jtoumani@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:39:23 by jtoumani          #+#    #+#             */
/*   Updated: 2025/07/17 19:03:10 by jtoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_scroll(double xdelta, double ydelta, void *param)
{
	t_struct	*f;
	double		zoom_old;
	int32_t		mouse_x;
	int32_t		mouse_y;

	f = (t_struct *)param;
	zoom_old = f->zoom;
	(void)xdelta;
	mlx_get_mouse_pos(f->mlx, &mouse_x, &mouse_y);
	if (ydelta > 0)
		f->zoom *= 1.1;
	else if (ydelta < 0)
		f->zoom /= 1.1;
	f->x_offset += (mouse_x - f->width / 2.0) * (4.0 / f->width) * (1 / zoom_old
			- 1 / f->zoom);
	f->y_offset += (mouse_y - f->height / 2.0) * (4.0 / f->height) * (1
			/ zoom_old - 1 / f->zoom);
}

void	handle_key(mlx_key_data_t keydata, void *param)
{
	t_struct	*fractol;
	double		move_step;

	fractol = (t_struct *)param;
	move_step = 0.1 / fractol->zoom;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(fractol->mlx);
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		fractol->y_offset -= move_step;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		fractol->y_offset += move_step;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		fractol->x_offset -= move_step;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		fractol->x_offset += move_step;
	else if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
	{
		fractol->color_shift = (fractol->color_shift + 1) % 3;
		draw_fractol(fractol);
	}
}
