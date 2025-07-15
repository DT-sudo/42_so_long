/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 21:41:45 by dtereshc          #+#    #+#             */
/*   Updated: 2025/07/15 09:37:51 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	validate_map_walls(t_game_map *game)
{
	size_t	x;
	size_t	y;
	size_t	rows_qnt;
	bool	eql_rows;

	if (!game || !game->map || !game->map_name)
		drop_error_ext(INVALID_POINTER, "Error: invalid pinter.\n", game->map);
	x = 0;
	rows_qnt = count_map_rows(game->map_name) - 1;
	while (game->map[x])
	{
		y = 0;
		if (x == 0 || x == rows_qnt)
		{
			eql_rows = (ft_strlen(game->map[0]) == ft_strlen(game->map[rows_qnt]));
			while (game->map[x][y])
			{
				if (!(game->map[x][y++] == '1') || !eql_rows)
					drop_error_ext(INVALID_MAP, "Error: map is invalid.\n",
						game->map);
			}
			x++;
		}
		else
		{
			eql_rows = (ft_strlen(game->map[0]) == ft_strlen(game->map[x]));
			if ((game->map[x][0] == '1' && game->map[x][ft_strlen(game->map[x])
					- 1] == '1') && eql_rows)
				x++;
			else
				drop_error_ext(INVALID_MAP, "Error: map is invalid.\n",
					game->map);
		}
	}
}

void	count_tiles(t_game_map *game, char tile_sign, size_t x, size_t y)
{
	if (tile_sign == 'E')
	{
		game->e_cordinates[0] = x;
		game->e_cordinates[1] = y;
		game->e++;
	}
	else if (tile_sign == 'P')
	{
		game->p_cordinates[0] = x;
		game->p_cordinates[1] = y;
		game->p++;
	}
	else if (tile_sign == 'C')
		game->c++;
}

void	check_tiles(t_game_map *game)
{
	size_t	x;
	size_t	y;

	x = 1;
	while (game->map[x])
	{
		y = 1;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'E')
				count_tiles(game, 'E', x, y);
			else if (game->map[x][y] == 'P')
				count_tiles(game, 'P', x, y);
			else if (game->map[x][y] == 'C')
				count_tiles(game, 'C', x, y);
			else if (game->map[x][y] == '1' || game->map[x][y] == '0')
				;
			else
				drop_error_ext(INVALID_MAP, "Error: map has incorrect signs.\n",
					game->map);
			y++;
		}
		x++;
	}
}

void	validate_e_p_c_qnt(t_game_map *game)
{
	if (game->e != 1)
	{
		printf("exit qnt: %d\n", game->e);
		drop_error_ext(INVALID_MAP, "Error: map should has exactly 1 exit.\n",
			game->map);
	}
	if (game->p != 1)
		drop_error_ext(INVALID_MAP,
			"Error: map should has exactly 1 starting position.\n", game->map);
	if (game->c < 1)
		drop_error_ext(INVALID_MAP,
			"Error: map should has at least 1 collectible.\n", game->map);
}

void	validate_map(t_game_map *game)
{
	validate_map_walls(game);
	check_tiles(game);
	validate_e_p_c_qnt(game);
	game->map_width = ft_strlen(game->map[0]);
	game->map_height = count_map_rows(game->map_name);
}
