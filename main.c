/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoumani <jtoumani@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:14:35 by jtoumani          #+#    #+#             */
/*   Updated: 2025/07/07 16:41:59 by jtoumani         ###   ########.fr       */
/*                                                     
                       */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_struct	fractol;

	parsing(argc, argv, &fractol);
	fractol.name = argv[1];
	init_fractol(&fractol);
	draw_fractol(&fractol);
	mlx_key_hook(fractol.mlx, &handle_key, &fractol);
	mlx_scroll_hook(fractol.mlx, &handle_scroll, &fractol);
	mlx_loop_hook(fractol.mlx, &draw_fractol, &fractol);
	mlx_loop(fractol.mlx);
	mlx_terminate(fractol.mlx);
	return (0);
}
