/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoumani <jtoumani@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:52:26 by jtoumani          #+#    #+#             */
/*   Updated: 2025/07/16 16:26:26 by jtoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_error(void)
{
	ft_printf("Usage:\n");
	ft_printf("  For Mandelbrot: ./fractol mandelbrot\n");
	ft_printf("  For Julia set: ./fractol julia <real> <imaginary>\n");
	ft_printf(" Where <real> and <imaginary>");
	ft_printf(" are numbers between	-2.0 and 2.0\n");
	ft_printf("    Example: ./fractol julia -0.835 -0.2321\n");
	exit(EXIT_FAILURE);
}
