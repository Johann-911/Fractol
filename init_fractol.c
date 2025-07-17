/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoumani <jtoumani@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:46:57 by jtoumani          #+#    #+#             */
/*   Updated: 2025/07/17 19:03:36 by jtoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_all(t_struct *fractol)
{
	fractol->zoom = 1.0;
	fractol->x_offset = 0.0;
	fractol->y_offset = 0.0;
	fractol->max_iter = 100;
	fractol->width = WIDTH;
	fractol->height = HEIGHT;
	fractol->color_shift = 0;
}

void	init_fractol(t_struct *fractol)
{
	init_all(fractol);
	fractol->mlx = mlx_init(WIDTH, HEIGHT, fractol->name, "true");
	if (!fractol->mlx)
		return (handle_error());
	fractol->image = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->image)
	{
		mlx_terminate(fractol->mlx);
		handle_error();
		return ;
	}
	if (mlx_image_to_window(fractol->mlx, fractol->image, 0, 0) < 0)
	{
		mlx_delete_image(fractol->mlx, fractol->image);
		mlx_terminate(fractol->mlx);
		handle_error();
	}
}

void	draw_fractol(void *param)
{
	t_struct	*f;
	int			x;
	int			y;
	int			iter;
	uint32_t	color;

	f = (t_struct *)param;
	y = -1;
	while (++y < f->height)
	{
		x = -1;
		while (++x < f->width)
		{
			calc_pos(f, x, y);
			if (ft_strncmp(f->name, "mandelbrot", 11) == 0)
				iter = mandelbrot(f->real, f->imag, f->max_iter);
			else if (ft_strncmp(f->name, "julia", 6) == 0)
				iter = julia_iter(f->real, f->imag, f);
			else
				iter = burning_ship(f->real, f->imag, f->max_iter);
			color = get_color(iter, f->max_iter, f->color_shift, f->name);
			mlx_put_pixel(f->image, x, y, color);
		}
	}
}

void	calc_pos(t_struct *f, int x, int y)
{
	f->real = (x - f->width / 2.0) * (4.0 / (f->width * f->zoom)) + f->x_offset;
	f->imag = (y - f->height / 2.0) * (4.0 / (f->height * f->zoom))
		+ f->y_offset;
}
