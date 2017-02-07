/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/02 15:53:18 by aratinau          #+#    #+#             */
/*   Updated: 2015/09/29 21:11:57 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "get_next_line.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# define COLOR 0xF857C6

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				nb_l;
	int				nb_c;
	int				pos_x;
	int				pos_y;
	int				zoom;
	float			theta_x;
	float			theta_y;
	float			theta_z;
	double			qualite;
	struct s_file	*file;
}					t_env;

typedef struct		s_file
{
	int				a;
	int				line;
	struct s_file	*next;
}					t_file;

typedef struct		s_xyz
{
	int				x;
	int				y;
	int				z;
}					t_xyz;

typedef struct		s_two_dim
{
	float			x1;
	float			y1;
	float			x2;
	float			y2;
}					t_two_dim;

typedef struct		s_node
{
	float			x;
	float			y;
	float			z;
	int				numero_node;
}					t_node;

typedef struct		s_edge
{
	int				a;
	int				b;
}					t_edge;

int					traitement_retour_ligne(char *s, t_env *e, t_file **file);
int					key_hook(int key_code, t_env *e);
int					mouse_hook(int button, int x, int y, t_env *e);
int					expose_hook(t_env *e);
void				file_append(t_file **ref, int a, int line);
void				trace(t_list **nodes, t_list **edges, t_env *e);
void				rotate_x(t_list **nodes, float	theta);
void				rotate_y(t_list **nodes, float	theta);
void				rotate_z(t_list **nodes, float	theta);
void				process_node(t_list **node_lst, t_file **file, t_env **e);
void				process_edge_first(t_list **edge_lst, t_env **e);
void				process_edge_last(t_list **edge_lst, t_env **e);
void				draw(t_file *file, t_env *e);

#endif
