/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:41:04 by dtereshc          #+#    #+#             */
/*   Updated: 2025/07/19 17:49:08 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// done
void	set_imgs(t_game_map *game, t_game_mlx *data)
{
	data->tile[0] = mlx_xpm_file_to_image(data->mlx, "assets/img/bed.xpm",
			TILE_SIZE, TILE_SIZE);
	if (data->tile[0])
		drop_error_ext(1, "\nCouldn't load the map\n", game->map);
	data->tile[1] = mlx_xpm_file_to_image(data->mlx, "assets/img/diamond.xpm",
			TILE_SIZE, TILE_SIZE);
	if (data->tile[1])
		drop_error_ext(1, "\nCouldn't load the map\n", game->map);
	data->tile[2] = mlx_xpm_file_to_image(data->mlx, "assets/img/ground.xpm",
			TILE_SIZE, TILE_SIZE);
	if (data->tile[2])
		drop_error_ext(1, "\nCouldn't load the map\n", game->map);
	data->tile[3] = mlx_xpm_file_to_image(data->mlx, "assets/img/person.xpm",
			TILE_SIZE, TILE_SIZE);
	if (data->tile[3])
		drop_error_ext(1, "\nCouldn't load the map\n", game->map);
	data->tile[4] = mlx_xpm_file_to_image(data->mlx, "assets/img/walls.xpm",
			TILE_SIZE, TILE_SIZE);
	if (data->tile[4])
		drop_error_ext(1, "\nCouldn't load the map\n", game->map);
}

// done
void	clean_imgs(t_game_mlx *data)
{
	int	i;

	i = 4;
	while (i >= 0 && data->tile[i])
		mlx_destroy_imag(data->mlx, data->tile[i--]);
}

// done
void	clean_mlx(t_game_mlx *data, t_game_map *game)
{
	clean_imgs(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free_map(game->map);
	exit(1);
}

// done
void	esc(t_game_mlx *data, t_game_map map)
{
	write(1, "\nExit\n", 6);
	clean_imgs(data);
	return (0);
}

void	init_func(t_game_map *game, t_game_mlx *data)
{
	t_game_mlx *data;

	data->mlx = mlx_init();
	if (!data->mlx)
		drop_error_ext(INVALID_POINTER, "MLX couldn't inicialize the pointer.",
			game->map);
	data->win = mlx_new_window(data->mlx, (int)game->map_width * TILE_SIZE,
			(int)game->map_width * TILE_SIZE, "So_long");
	if (!data->win)
		drop_error_ext(INVALID_POINTER, "MLX couldn't creat the game window :(",
			game->map);
	set_imgs(game, data);
	make_map(game, data);
	// 	display_move_counter(game);
	mlx_key_hook(data->win, move_kyes, game);
	mlx_loop(data->mlx);
}
