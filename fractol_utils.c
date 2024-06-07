/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:22:50 by esellier          #+#    #+#             */
/*   Updated: 2024/06/07 17:56:12 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_args	*create_struct(t_args *args)
{	
	args = ((t_args *)malloc(sizeof * (t_args)));
	if (!args)
		exit(1);
	args->x = 0;
	args->y = 0;
	return (args);	
}

void	*final_free(t_args *args)
{
	if (args)
	{
		if (test)
			free (test);
	}
	free (args);
	return;
}


void	*check_two(char **argv)
{
	if (ft_strncmp(argv[1], "mandelbrot", 10) != 0
		|| ft_strncmp(argv[1], "Mandelbrot", 10) != 0)
	{
		if (ft_strncmp(argv[1], "mandelbrot", 5) == 0
			|| ft_strncmp(argv[1], "Mandelbrot", 5) == 0)
			return (write(2, "Do you mean \"Mandelbrot\"?\n", 26));
		if (ft_strncmp(argv[1], "mendelbrot", 5) == 0
			|| ft_strncmp(argv[1], "Mendelbrot", 5) == 0)
			return (write(2, "Do you mean \"Mandelbrot\"?\n", 26));
		if (ft_strncmp(argv[1], "Julia", 3) == 0
			|| ft_strncmp(argv[1], "julia", 3) == 0)
			return (write(2, "Miss first point size to Julia's form\n", 38));
		else
			write(2, "Bad request, use Julia or Mandelbrot fractal\n", 45);
		exit(1);           
	}
}


void    *check_four(char **argv, t_args *args)
{
	if (ft_strncmp(argv[1], "julia", 5) != 0
			 || ft_strncmp(argv[1], "Julia", 5) != 0)
	{
		if (ft_strncmp(argv[1], "julia", 3 == 0
			|| ft_strncmp(argv[1], "Julia", 3) == 0))
			return (write(2, "Do you mean \"Julia\"?\n", 21));
		else
			write(2, "Bad request, use Julia or Mandelbrot fractal\n", 45);
		exit(1);
	}
	if (ft_strncmp(argv[1], "julia", 5) == 0
			 || ft_strncmp(argv[1], "Julia", 5) == 0)
	{     
		args->x = atoi_double(argv[2]);
		args->y = atoi_double(argv[3]);	
	}
}

void    *check_args(int argc, char **argv, t_args *args)
{
	if (argc != 2 && argc != 4)
	{
		write(2, "Bad request, not enough or too much arguments\n", 46);
		exit(1);
	}
	args = create_struct(args);
	if (argc == 2)
		check_two(argv);        
	if (argc == 4)
		check_four(argv, args);    
}
