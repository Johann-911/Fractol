/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoumani <jtoumani@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:16:58 by jtoumani          #+#    #+#             */
/*   Updated: 2025/07/17 18:43:08 by jtoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	double_value(char *str, int i)
{
	double	nbr;
	double	factor;

	nbr = 0.0;
	factor = 1.0;
	while (ft_isdigit(str[i]))
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (ft_isdigit(str[i]))
		{
			factor = factor / 10;
			nbr = nbr + (str[i] - '0') * factor;
			i++;
		}
	}
	return (nbr);
}

double	atod(char *str)
{
	double	result;
	int		sign;
	int		i;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = double_value(str, i);
	return (sign * result);
}

bool	is_valid_nbr(char *str)
{
	double	nbr;

	if (!str || !*str)
		return (false);
	if (*str == '-' || *str == '+')
		str++;
	if (!*str || !(*str >= '0' && *str <= '9'))
		return (false);
	while (*str)
	{
		if (!((*str >= '0' && *str <= '9') || *str == '.'))
			return (false);
		str++;
	}
	nbr = atod(str);
	if (nbr > 2 || nbr < -2)
		return (false);
	return (true);
}

void	parsing(int argc, char **argv, t_struct *fractol)
{
	if (argc == 2)
	{
		if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
			fractol->name = "mandelbrot";
		else if (ft_strncmp(argv[1], "burning_ship", 13) == 0)
			fractol->name = "burning_ship";
		else
			handle_error();
	}
	else if (argc == 4)
	{
		if ((ft_strncmp(argv[1], "julia", 6) != 0) || (!is_valid_nbr(argv[2]))
			|| (!is_valid_nbr(argv[3])))
		{
			handle_error();
		}
		fractol->name = "julia";
		fractol->c_real = atod(argv[2]);
		fractol->c_imag = atod(argv[3]);
	}
	else
		handle_error();
}
