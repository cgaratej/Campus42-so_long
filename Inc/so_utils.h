/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:09:20 by cgaratej          #+#    #+#             */
/*   Updated: 2024/04/16 14:23:51 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_UTILS_H
# define SO_UTILS_H

# define UP		119
# define DOWN	115
# define LEFT	97
# define RIGHT	100
# define ESC	65307
# define RED	"\033[1m\033[31m"
# define GREEN	"\033[1m\033[32m"
# define ENDC	"\033[0m"
# define SPRITE_SIZE	32

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define MLX_ERROR 1

enum e_map
{
	floor = 0,
	wall = 1,
	collect = 'C',
	portal = 'E',
	player = 'P',
};

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
}		t_img;

typedef struct s_counter
{
	int		empty;
	int		collectible;
	int		exit;
	int		start;
	int		movements;
}		t_counter;

typedef struct s_draw
{
	char	**map;
	int		height;
	int		length;
	char	*line;
}	t_draw;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*window_ptr;
	t_draw		plot;
	t_counter	i;	
	t_img		sprite;
	t_img		sprite_l;
	t_img		sprite_r;
	t_img		sprite_f;
	t_img		floor;
	t_img		tree;
	t_img		collect;
	t_img		portal;
}		t_game;

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

#endif