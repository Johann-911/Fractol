/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoumani <jtoumani@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:59:09 by jtoumani          #+#    #+#             */
/*   Updated: 2025/07/17 19:04:03 by jtoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_iter(double real, double imag, t_struct *f)
{
	double	z_real;
	double	z_imag;
	double	temp;
	int		iter;

	z_real = real;
	z_imag = imag;
	iter = 0;
	while (iter < f->max_iter)
	{
		temp = z_real * z_real - z_imag * z_imag;
		z_imag = 2 * z_real * z_imag + f->c_imag;
		z_real = temp + f->c_real;
		if (z_real * z_real + z_imag * z_imag > 4)
			break ;
		iter++;
	}
	return (iter);
}
