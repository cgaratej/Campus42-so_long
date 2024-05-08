/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imagen_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:03:18 by cgaratej          #+#    #+#             */
/*   Updated: 2024/05/08 14:01:43 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	init_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if ((game->plot.length * SPRITE_SIZE) >= 1920 \
		|| (game->plot.height * SPRITE_SIZE) >= 720)
	{
		free_map(&game->plot);
		free(game->mlx_ptr);
		game_over("Map size larger than display resolution", game, error);
	}
	else
	{
		game->window_ptr = mlx_new_window(game->mlx_ptr, \
			(game->plot.length * SPRITE_SIZE), \
			(game->plot.height * SPRITE_SIZE), "./so_long_bonus");
	}
}

void	init_images(t_game *game)
{
	game->sprite = new_sprite(game->mlx_ptr, PATH_SPRITE);
	game->sprite_l = new_sprite(game->mlx_ptr, PATH_SPRITE_L);
	game->sprite_r = new_sprite(game->mlx_ptr, PATH_SPRITE_R);
	game->sprite_f = new_sprite(game->mlx_ptr, PATH_SPRITE_F);
	game->floor = new_sprite(game->mlx_ptr, PATH_FLOOR);
	game->tree = new_sprite(game->mlx_ptr, PATH_TREE);
	game->coin = new_sprite(game->mlx_ptr, PATH_COIN);
	game->door = new_sprite(game->mlx_ptr, PATH_DOOR);
	game->door_open = new_sprite(game->mlx_ptr, PATH_DOOR_OPEN);
	game->spikes = new_sprite(game->mlx_ptr, PATH_SPIKES);
	game->sprite.mem = 0;
}

t_img	new_sprite(void *mlx, char *path)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx, path, &img.h, &img.w);
	return (img);
}