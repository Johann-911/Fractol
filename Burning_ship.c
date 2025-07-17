/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoumani <jtoumani@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:19:06 by jtoumani          #+#    #+#             */
/*   Updated: 2025/07/16 16:13:41 by jtoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burning_ship(double real, double imag, int max_iter)
{
	double	z_real;
	double	z_imag;
	double	temp;
	int		iter;

	z_real = 0;
	z_imag = 0;
	iter = 0;
	while (iter < max_iter)
	{
		temp = z_real * z_real - z_imag * z_imag + real;
		z_imag = fabs(2 * z_real * z_imag) + imag;
		z_real = fabs(temp);
		if (z_real * z_real + z_imag * z_imag > 4)
			break ;
		iter++;
	}
	return (iter);
}
