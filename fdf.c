/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/28 18:36:02 by aratinau          #+#    #+#             */
/*   Updated: 2015/09/29 21:13:04 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_if_error(int argc, char **argv)
{
	int		str_len;

	if (argc != 2)
	{
		color_str("ERROR ARGUMENTS add a map\n", "41;1");
		exit(0);
	}
	str_len = ft_strlen(argv[1]);
	str_len--;
	if (argv[1][str_len] != 'f' || argv[1][str_len - 1] != 'd' ||
			argv[1][str_len - 2] != 'f' || argv[1][str_len - 3] != '.')
	{
		color_str("ERROR FILE NAME\n", "41;1");
		exit(0);
	}
}

void	init_e(t_env *e)
{
	e->nb_l = 1;
	e->nb_c = 0;
	e->pos_x = 500;
	e->pos_y = 800;
	e->zoom = 30;
	e->theta_x = -3;
	e->theta_y = -14;
	e->theta_z = 0;
	e->qualite = 0.5;
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*retour_function;
	t_env	e;
	t_file	*file;

	check_if_error(argc, argv);
	init_e(&e);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1000, 1000, "fdf");
	file = NULL;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &retour_function) == 1)
	{
		traitement_retour_ligne(retour_function, &e, &file);
		e.nb_l++;
	}
	e.nb_l--;
	e.file = file;
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
