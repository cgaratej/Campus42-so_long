/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:37:28 by cgaratej          #+#    #+#             */
/*   Updated: 2024/04/29 10:41:36 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	is_ber_file(const char *argv)
{
	char	*string;

	string = ft_strrchr(argv, '.');
	if (string)
		return (ft_strncmp(string, ".ber", ft_strlen(string)) == 0);
	return (0);
}

static void	init_game(t_game *game, char *path)
{
	init_map(game, path);
	init_window(game);
	init_images(game);
	render_map(game, 1);
	mlx_loop(game->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc > 2)
		game_over("Can't open multiple files!", &game, error);
	else if (argc < 2)
		game_over("Please specify file name!", &game, error);
	else if (argc == 2)
	{
		if (is_ber_file(argv[1]))
			init_game(&game, argv[1]);
		else
			game_over("The file is invalid!", &game, error);
	}
	return (0);
}
