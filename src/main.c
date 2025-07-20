/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:49:34 by dtereshc          #+#    #+#             */
/*   Updated: 2025/07/19 16:14:19 by dt               ###   ########.fr       */
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
	game->step = 0;
	validate_arguments(argc, argv);
	game->map_name = argv[1];
	game->map = creat_map(game);
	validate_map(game);
	collectibles_exit(game);
	
	free_map(game->map);
	return (0);
}
