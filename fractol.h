/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoumani <jtoumani@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:25:58 by jtoumani          #+#    #+#             */
/*   Updated: 2025/07/17 19:33:47 by jtoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "Libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "Printf/ft_printf.h"
# include <math.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# define HEIGHT 500
# define WIDTH 500

typedef struct s_struct
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	char		*name;
	double		zoom;
	double		x_offset;
	double		y_offset;
	int			max_iter;
	int			width;
	int			height;
	double		c_real;
	double		c_imag;
	double		real;
	double		imag;
	u_int32_t	color;
	int			color_shift;
}				t_struct;

void			init_fractol(t_struct *fractol);
void			init_all(t_struct *fractol);
void			parsing(int argc, char **argv, t_struct *fractol);
void			draw_fractol(void *param);
void			handle_key(mlx_key_data_t keydata, void *param);
void			handle_scroll(double xdelta, double ydelta, void *param);
double			atod(char *str);
bool			is_valid_nbr(char *str);
void			handle_error(void);
int				mandelbrot(double real, double imag, int max_iter);
int				julia_iter(double real, double imag, t_struct *f);
int				burning_ship(double real, double imag, int max_iter);
uint32_t		get_color(int iter, int max_iter, int shift, const char *name);
void			calc_pos(t_struct *f, int x, int y);
uint32_t		get_color_two(double t, int mode);

#endif