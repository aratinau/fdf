/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 20:02:56 by aratinau          #+#    #+#             */
/*   Updated: 2015/09/29 20:35:52 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_hook_part_next(int key_code, t_env *e)
{
	if (key_code == 124) // ok
		e->pos_x = e->pos_x + 10;
	if (key_code == 125) // ok
		e->pos_y = e->pos_y + 10;
	if (key_code == 123) // ok
		e->pos_x = e->pos_x - 10;
	if (key_code == 126) // ok
		e->pos_y = e->pos_y - 10;
	if (key_code == 24) // -
		e->zoom--;
	if (key_code == 44) // +
		e->zoom++;
	if (key_code == 43) // ,
		e->qualite = 0.5;
	if (key_code == 46) // ;
		e->qualite = 5;
}

int		key_hook(int key_code, t_env *e)
{
	t_file *p_file;

	p_file = e->file;
	if (key_code == 53)
		exit(0);
	if (key_code == 1) // s
		e->theta_x = e->theta_x + 0.5;
	if (key_code == 13) // z
		e->theta_x = e->theta_x - 0.5;
	if (key_code == 2) // d
		e->theta_y = e->theta_y + 0.5;
	if (key_code == 0) // q
		e->theta_y = e->theta_y - 0.5;
	if (key_code == 14) // e
		e->theta_z = e->theta_z + 0.5;
	if (key_code == 12) // a
		e->theta_z = e->theta_z - 0.5;
	key_hook_part_next(key_code, e);
	mlx_clear_window(e->mlx, e->win);
	draw(p_file, e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	t_file *p_file;

	p_file = e->file;
	if (button == 1)
	{
		e->pos_x = x;
		e->pos_y = y;
		mlx_clear_window(e->mlx, e->win);
		draw(p_file, e);
	}
	return (0);
}

int		expose_hook(t_env *e)
{
	t_file *p_file;

	p_file = e->file;
	draw(p_file, e);
	return (0);
}
