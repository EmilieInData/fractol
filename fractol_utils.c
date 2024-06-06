/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:22:50 by esellier          #+#    #+#             */
/*   Updated: 2024/06/06 18:56:22 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
            return (write(2, "Do you mean \"Julia\"?\n", 21);
        else
            write(2, "Bad request, use Julia or Mandelbrot fractal\n", 45);
        exit(1);
    }
    if (ft_strncmp(argv[1], "julia", 5) == 0
             || ft_strncmp(argv[1], "Julia", 5) == 0)
    {     
        if (argv[2] && argv[3])    ne respectent pas le tableau de  taille avec decimal (DOUBLE) atoi double
        // faire fonction (checker qu´íl y a bien quúne seule virgule, gerer le signe moins et plus, attention au 0, ni moins ni plus devant (pb parcing push swap))
    }
        
        






}

void    *args_errors(int argc, char **argv)
{
    if (argc == 2)
        errors_two(argc, argv);        
    if (argc == 4)
        errors_four(argc, argv);    
        
    }
    if (argc != 2 && argc != 4)
        return (write(2, "Bad request, use Julia or Mandelbrot fractal\n", 45));
    return(0);
}

