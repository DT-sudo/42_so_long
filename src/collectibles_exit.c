/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 20:44:27 by dtereshc          #+#    #+#             */
/*   Updated: 2025/07/19 16:08:13 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	reach_every_E_C(t_game_map *game, size_t x, size_t y)
{
	if ((game->map_height - 1) >= x && (game->map_width - 1) >= y)
	{
		if (!game || !game->map || !game->map_name)
			drop_error_ext(INVALID_POINTER, "Error: invalid pinter.\n",
				game->map);
		if (game->map[x][y] == 'P')
		{
			game->p_cordinates[0] = x;
			game->p_cordinates[1] = y;
			game->map[x][y] = 'p';
		}
		else if (game->map[x][y] == '0')
			game->map[x][y] = 'o';
		else if (game->map[x][y] == 'C')
			game->map[x][y] = 'c';
		else if (game->map[x][y] == 'E')
		{
			game->e_cordinates[0] = x;
			game->e_cordinates[1] = y;
			game->map[x][y] = 'e';
			return ;
		}
		else if (game->map[x][y] == 'p' || game->map[x][y] == 'e'
			|| game->map[x][y] == 'o' || game->map[x][y] == 'c'
			|| game->map[x][y] == '1')
			return ;
		reach_every_E_C(game, x + 1, y);
		reach_every_E_C(game, x, y + 1);
		reach_every_E_C(game, x - 1, y);
		reach_every_E_C(game, x, y - 1);
	}
	else
		return ;
}

void	find_E_C_P_restore(t_game_map *game)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'E' || game->map[x][y] == 'C')
			{
				drop_error_ext(INVALID_MAP,
					"Error: E or some C are not reachable.\n", game->map);
			}
			else if (game->map[x][y] == 'e' || game->map[x][y] == 'c'
				|| game->map[x][y] == 'p')
				game->map[x][y] = game->map[x][y] - 32;
			else if (game->map[x][y] == 'o')
				game->map[x][y] = '0';
			y++;
		}
		x++;
	}
}

void	set_P_cordinates(t_game_map *game)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'P')
			{
				game->p_cordinates[0] = x;
				game->p_cordinates[1] = y;
				return ;
			}
			y++;
		}
		x++;
	}
}
void	collectibles_exit(t_game_map *game)
{
	set_P_cordinates(game);
	reach_every_E_C(game, game->p_cordinates[0], game->p_cordinates[1]);
	find_E_C_P_restore(game);
}
