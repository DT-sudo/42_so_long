/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:49:34 by dtereshc          #+#    #+#             */
/*   Updated: 2025/07/14 21:23:48 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game_map *game;
	
	game = malloc(sizeof(t_game_map));
	if (!game)
    	return (1);
	game->map_name = NULL;
	game->map = NULL;
	game->c = 0;
	game->p = 0;
	game->e = 0;
	validate_arguments(argc, argv);
	game->map_name = argv[1];
	game->map = creat_map(game);
	validate_map(game);
	collectibles_exit(game);
	// size_t x;
	// size_t y;
	// x = 0;
	// while (game->map[x])
	// {
	// 	y = 0;
	// 	while (game->map[x][y])
	// 	{
	// 		// printf("%d elment has cordinates x:%zu, y:%zu. Value: %c", i, x, y, game->map[x][y]);	
	// 		printf("%c", game->map[x][y]);	
	// 		y++;
	// 	}
	// 	printf("\n");
	// 	x++;
	// }
	
	// printf("The map is valid! :3");
	free_map(game->map);
	return (0);
}
