/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:26:49 by dt                #+#    #+#             */
/*   Updated: 2025/07/19 17:55:17 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// done
void	make_map_logic(t_game_map *game, t_game_mlx *data, size_t x, size_t y)
{
	if (game->map[x][y] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->tile[4], x
			* TILE_SIZE, y * TILE_SIZE);
	else if (game->map[x][y] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->tile[2], x
			* TILE_SIZE, y * TILE_SIZE);
	else if (game->map[x][y] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->tile[0], x
			* TILE_SIZE, y * TILE_SIZE);
	else if (game->map[x][y] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->tile[3], x
			* TILE_SIZE, y * TILE_SIZE);
	else if (game->map[x][y] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->tile[1], x
			* TILE_SIZE, y * TILE_SIZE);
}

// done
void	make_map(t_game_map *game, t_game_mlx *data)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x <= (game->map_height - 1))
	{
		y = 0;
		while (y <= (game->map_width - 1))
		{
			make_map_logic(game, data, x, y);
			y++;
		}
		x++;
	}
}

void	show_moves(t_game_map *game)
{
}

void	update_p_cordinates(t_game_map *game, size_t new_p_x, size_t new_p_y)
{
	game->map[game->p_cordinates[0]][game->p_cordinates[1]] = '0';
	game->p_cordinates[0] = new_p_x;
	game->p_cordinates[1] = new_p_y;
}

void	move(t_game_map *game, t_game_mlx *data, size_t next_x, size_t next_y)
{
	if (game->map[next_x][next_y] == '0')
		game->map[next_x][next_y] = 'P';
	else if (game->map[next_x][next_y] == 'C')
	{
		game->map[next_x][next_y] = 'P';
		game->c--;
	}
	else if (game->map[next_x][next_y] == '1' || (game->c != 0
			&& game->map[next_x][next_y] == 'E'))
		return ;
	else if (game->c == 0 && game->map[next_x][next_y] == 'E')
	{
		game->step++;
		ft_printf("\nMoves: %d\n", game->step);
		clean_mlx(data, game);
	}
	update_p_cordinates(game, next_x, next_y);
	make_map(game, data);
	game->step++;
	ft_printf("\nMoves: %d\n", game->step);
	// display_move_counter game);
}

// done
int	move_kyes(int k_num, t_game_map *game, t_game_mlx *data)
{
	int	next_x;
	int	next_y;

	next_x = game->p_cordinates[0];
	next_y = game->p_cordinates[1];
	if (k_num == 65363 || k_num == 100)
		next_x++;
	else if (k_num == 65361 || k_num == 97)
		next_x--;
	else if (k_num == 65364 || k_num == 115)
		next_y++;
	else if (k_num == 65362 || k_num == 119)
		next_y--;
	else if (k_num == 65307)
	{
		clean_mlx(data, game);
		return (0);
	}
	move(game, data, next_x, next_y);
	return (0);
}
