/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:22:50 by esellier          #+#    #+#             */
/*   Updated: 2024/06/23 21:10:13 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_two(char **argv)
{
	if (ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])) != 0
		&& ft_strncmp(argv[1], "Mandelbrot", ft_strlen(argv[1])) != 0
		&& ft_strncmp(argv[1], "MANDELBROT", ft_strlen(argv[1])) != 0)
	{
		if (ft_strncmp(argv[1], "mandelbrot", 5) == 0
			|| ft_strncmp(argv[1], "Mandelbrot", 5) == 0
			|| ft_strncmp(argv[1], "MANDELBROT", 5) == 0
			|| ft_strncmp(argv[1], "mendelbrot", 5) == 0
			|| ft_strncmp(argv[1], "Mendelbrot", 5) == 0
			|| ft_strncmp(argv[1], "MENDELBROT", 5) == 0)
			write(STDERR_FILENO, "Do you mean \"Mandelbrot\"?\n", 26);
		else if (ft_strncmp(argv[1], "Julia", 5) == 0
			|| ft_strncmp(argv[1], "julia", 5) == 0
			|| ft_strncmp(argv[1], "JULIA", 5) == 0)
			write(STDERR_FILENO, "Miss first points to Julia's form\n", 34);
		else if ((ft_strncmp(argv[1], "B", 1) == 0)
			|| (ft_strncmp(argv[1], "b", 1) == 0))
			return (1);
		else
			write(STDERR_FILENO,
				"Use Julia, Mandelbrot or Burningship fractal\n", 46);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	check_four(char **argv)
{
	if (ft_strncmp(argv[1], "julia", ft_strlen(argv[1])) != 0
		&& ft_strncmp(argv[1], "Julia", ft_strlen(argv[1])) != 0
		&& ft_strncmp(argv[1], "JULIA", ft_strlen(argv[1])) != 0)
	{
		if (ft_strncmp(argv[1], "julia", 3) == 0
			|| ft_strncmp(argv[1], "Julia", 3) == 0
			|| ft_strncmp(argv[1], "JULIA", 3) == 0)
			write(STDERR_FILENO, "Do you mean \"Julia\"?\n", 21);
		else
			write(STDERR_FILENO,
				"Use Julia, Mandelbrot or Burningship fractal\n", 46);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	check_bonus(char **argv)
{
	if (ft_strncmp(argv[1], "burningship", ft_strlen(argv[1])) != 0
		&& ft_strncmp(argv[1], "Burningship", ft_strlen(argv[1])) != 0
		&& ft_strncmp(argv[1], "BURNINGSHIP", ft_strlen(argv[1])) != 0)
	{
		if (ft_strncmp(argv[1], "burningship", 4) == 0
			|| ft_strncmp(argv[1], "Burningship", 4) == 0
			|| ft_strncmp(argv[1], "BURNINGSHIP", 4) == 0)
			write(STDERR_FILENO, "Do you mean \"Burningship\"?\n", 27);
		else
			write(STDERR_FILENO,
				"Use Julia, Mandelbrot or Burningship fractal\n", 45);
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	*check_args(int argc, char **argv)
{
	if (argc != 2 && argc != 4)
	{
		write(STDERR_FILENO, "Not enough or too much arguments, use Julia,"
			"Mandelbrot or Burningship fractal\n", 79);
		exit(EXIT_FAILURE);
	}
	if (argc == 2)
	{
		check_two(argv);
		if (check_two(argv) == 1)
			check_bonus(argv);
	}
	if (argc == 4)
		check_four(argv);
	return (0);
}

void	*create_structs(t_data **data, int argc, char **argv)
{
	*data = ((t_data *)malloc(sizeof(t_data)));
	if (!*data)
		exit(EXIT_FAILURE);
	(*data)->image = ((t_img *)malloc(sizeof(t_img)));
	if (!(*data)->image)
		data_free(*data);
	if (argc == 2)
	{
		if (strncmp(argv[1], "M", 1) == 0 || strncmp(argv[1], "m", 1) == 0)
			(*data)->name = "Mandelbrot";
		else
			(*data)->name = "Burningship";
	}
	if (argc == 4)
	{
		(*data)->name = "Julia";
		(*data)->julia_x = atoi_double(argv[2], 0);
		(*data)->julia_y = atoi_double(argv[3], 0);
	}
	(*data)->range = 0;
	(*data)->move_x = 0.00;
	(*data)->move_y = 0.00;
	(*data)->zoom = 1.00;
	return (0);
}
