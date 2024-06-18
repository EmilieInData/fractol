/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:22:50 by esellier          #+#    #+#             */
/*   Updated: 2024/06/18 19:59:07 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_two(char **argv)
{
	if (ft_strncmp(argv[1], "mandelbrot", 10) != 0
		&& ft_strncmp(argv[1], "Mandelbrot", 10) != 0 // check wth Mandelbrotttt Ou juliaaaa?
		&& ft_strncmp(argv[1], "MANDELBROT", 10) != 0)
	{
		if (ft_strncmp(argv[1], "mandelbrot", 5) == 0
			|| ft_strncmp(argv[1], "Mandelbrot", 5) == 0
			|| ft_strncmp(argv[1], "MANDELBROT", 5) == 0)
			write(STDERR_FILENO, "Do you mean \"Mandelbrot\"?\n", 26);
		if (ft_strncmp(argv[1], "mendelbrot", 5) == 0
			|| ft_strncmp(argv[1], "Mendelbrot", 5) == 0
			|| ft_strncmp(argv[1], "MENDELBROT", 5) == 0)
			write(STDERR_FILENO, "Do you mean \"Mandelbrot\"?\n", 26);
		if (ft_strncmp(argv[1], "Julia", 5) == 0
			|| ft_strncmp(argv[1], "julia", 5) == 0
			|| ft_strncmp(argv[1], "JULIA", 5) == 0)
			write(STDERR_FILENO, "Miss first points sizes to Julia's form\n", 40);
		else
			write(STDERR_FILENO, "Bad request, use Julia or Mandelbrot fractal\n", 45);
		exit(EXIT_FAILURE);           
	}
	return (0);
}

int    check_four(char **argv, t_data *data)
{
	if (ft_strncmp(argv[1], "julia", 5) != 0
			 && ft_strncmp(argv[1], "Julia", 5) != 0
			 && ft_strncmp(argv[1], "JULIA", 5) != 0)
	{
		if (ft_strncmp(argv[1], "julia", 3) == 0
			|| ft_strncmp(argv[1], "Julia", 3) == 0
			|| ft_strncmp(argv[1], "JULIA", 3) == 0)
			write(STDERR_FILENO, "Do you mean \"Julia\"?\n", 21);
		else
			write(STDERR_FILENO, "Bad request, use Julia or Mandelbrot fractal\n", 45);
		exit(EXIT_FAILURE);
	}
	/*if (ft_strncmp(argv[1], "julia", 5) == 0
			 || ft_strncmp(argv[1], "Julia", 5) == 0
		 	 || ft_strncmp(argv[1], "JULIA", 5) == 0)
	{ */    
		data->julia_x = atoi_double(argv[2]);
		data->julia_y = atoi_double(argv[3]);	
	//}
	return (0);
}

void    *check_args(int argc, char **argv, t_data *data)
{
	if (argc != 2 && argc != 4)
	{
		write(STDERR_FILENO, "Bad request, not enough or too much arguments,\nuse Julia or Mandelbrot set!\n", 76);
		exit(EXIT_FAILURE);
	}
	if (argc == 2)
		check_two(argv);        
	if (argc == 4)
		check_four(argv, data);
	return (0);
}

void	*create_structs(t_data **data)
{	
	*data = ((t_data *)malloc(sizeof(t_data)));
	if (!*data)
		exit(EXIT_FAILURE);
	(*data)->image = ((t_img *)malloc(sizeof(t_img)));
	if (!(*data)->image)
	{
		free(*data);
		exit(EXIT_FAILURE);
	}
	(*data)->outside_fractal = 4;
	(*data)-> def_iterations = 40;
	(*data)-> move_x = 0.00;
	(*data)-> move_y = 0.00;
	(*data)-> zoom = 1.00;
	return (0);	
}

void	*data_free(t_data *data)
{
	if (data)
	{
		if (data->image->img_add)
			mlx_destroy_image(data->init, data->image->img_add);
		if (data->window)
			mlx_destroy_window(data->init, data->window);
		if (data->init)
			mlx_destroy_display(data->init);
		if (data->image)
			free (data->image);
		free (data);
	}
	exit (EXIT_FAILURE);
}