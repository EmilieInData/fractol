/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:22:50 by esellier          #+#    #+#             */
/*   Updated: 2024/06/07 14:53:42 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double  atoi_double(char *str)
{
	int	i;
	double sign;
	double	r;
	double	r2;
	
	r = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || str[i] > 8 && str[i] < 14)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + str[i] -'0'; 
		i++;
	}
	if (str[i] == ',')
	{
			write(2,"Error, please use \".\" instead of \",\"\n", 37);
			exit(1);
	}
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r2 = (r2 * 10) + str[i] -'0';
		i++;
	}
	while (r2 > 1)
		r2 = r2 / 10;
	r = r + r2;
	return (r * sign);
}

void    *errors_two(int argc, char **argv)
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
	return (0);
}

void    *errors_four(int argc, char **argv)
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
		 ne respectent pas le tableau de  taille avec decimal (DOUBLE) atoi double
		// faire fonction (checker qu´íl y a bien quúne seule virgule, gerer le signe moins et plus, attention au 0, ni moins ni plus devant (pb parcing push swap))
		si fonction ok return 0 sinon exit et message d erreurs  
		atoi_double(argv[2]);
		atoi_double(argv[3]);	
	}
}

void    *args_errors(int argc, char **argv)
{
	if (argc == 2)
		errors_two(argc, argv);        
	if (argc == 4)
		errors_four(argc, argv);    
	else
	{
		write(2, "Bad request, not enough or too much arguments\n", 46);
		exit(1);
	}	
	return;
}

