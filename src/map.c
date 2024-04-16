/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:42:56 by cgaratej          #+#    #+#             */
/*   Updated: 2024/04/16 14:55:38 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	read_map(t_game *game, int fd)
{
	char	*tmp;

	tmp = ft_strdup("");
	game->plot.height = 0;
	while (fd)
	{
		game->plot.line = get_next_line(fd);
		if (game->plot.line == NULL)
			break ;
		free(game->plot.line);
		game->plot.height++;
	}
	game->plot.map = ft_split(tmp, '\n');
	free(tmp);
	return ;
}

void	init_map(t_game *game, char *path)
{
	int	fd;

	fd = open_file(path);
	read_map(game, fd);
	game->plot.length = len_map_validation(game->plot.map, game);
	close(fd);
	return ;
}