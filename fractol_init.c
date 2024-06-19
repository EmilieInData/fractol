/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:28:50 by esellier          #+#    #+#             */
/*   Updated: 2024/06/19 18:43:34 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int do_key(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
        close_escape(data);
    if (keysym == XK_Up)
        data->move_y = data->move_y - 0.3 * data->zoom;
    if (keysym == XK_Down)
        data->move_y = data->move_y + 0.3 * data->zoom;
    if (keysym == XK_Left)
        data->move_x = data->move_x + 0.3 * data->zoom;
    if (keysym == XK_Right)
        data->move_x = data->move_x - 0.3 * data->zoom;
    //definir une touche pour les changements de couleurs
    create_fractal(data);
    return (0);
}

int do_mouse(int button, int x, int y, t_data *data)
{
    (void) x;
    (void) y;
    
    if (button == Button4) //mollette pour le zoom
        data->zoom = data->zoom * 1.10;
    if (button == Button5)
        data->zoom = data->zoom * 0.90;
   
    //resize la fenetre si on essaie de la redimensionner avec la souris
    create_fractal(data);
    return(0);
}

/*int do_mouse_mvmt(int x, int y, t_data *data)
{
 //BONUS:position de la souris pour le zoom
    if (ft_strncmp(argv[1], "julia", 5) == 0
			 || ft_strncmp(argv[1], "Julia", 5) == 0
		 	 || ft_strncmp(argv[1], "JULIA", 5) == 0)
    {
     
    
    }
}*/
/*static int	mouse_event(int mouse_code, int x, int y, t_fractol *f)
{
	double	p_x;
	double	p_y;
	double	zoom_factor;

	p_x = ((double)x * 4 / WIDTH - 2) * f->zoom + f->shift.x;
	p_y = ((double)y * 4 / HEIGHT - 2) * f->zoom + f->shift.y;
	if (mouse_code == ON_MOUSEDOWN)
	{
		zoom_factor = 1.1;
		f->shift.x += (p_x - f->shift.x) * (1 - zoom_factor);
		f->shift.y += (p_y - f->shift.y) * (1 - zoom_factor);
		f->zoom *= zoom_factor;
	}
	if (mouse_code == ON_MOUSEUP)
	{
		zoom_factor = 0.9;
		f->shift.x += (p_x - f->shift.x) * (1 - zoom_factor);
		f->shift.y += (p_y - f->shift.y) * (1 - zoom_factor);
		f->zoom *= zoom_factor;
	}
	render(f);*/

void    init_events(t_data *data)
{
    //mlx_hook(data->window, int KeyPress, int KeyPressMask, int fonction a creer, data);
    mlx_key_hook(data->window, do_key, data); //keyboard
    mlx_hook(data->window, 17, (1L << 5), close_escape, data); //windows cross
    mlx_mouse_hook(data->window, do_mouse, data);//mouse
    //mlx_hook(data->window, MotionNotify, PointerMotionMask, do_mouse_mvmt, data);
    //buttons
    //??
    //va checker l'action repertoriee est en fonction de la fonction appliquée
    //creer un evenement
}

int	close_escape(t_data *data)
{
	mlx_destroy_image(data->init, data->image->img_add);
	mlx_destroy_window(data->init, data->window);
	mlx_destroy_display(data->init);
	free (data->image);
	free (data);
	exit (EXIT_SUCCESS);
}