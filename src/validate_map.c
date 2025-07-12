/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 21:41:45 by dtereshc          #+#    #+#             */
/*   Updated: 2025/07/12 19:10:08 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Validates all tiles of the map
// wether it's only 0, 1, C, E, P
// counts if there is only one P rights down it coordinates
// counts if there is only one E rights down it coordinates
// counts if there is at least one C
// if the map fully sorounded by walles
// if map is rectangular
// if smth wrang passes coresponding error

#include "so_long.h"

// tile checker if not drop_error
void	check_tile(void)
{
    
}

// checks if E/P == 1 and C > 0 if not drop_error
void	validate_e_p_c(void)
{
}

// goes throgh the whole map and cheks every tile
void	validate_map(void)
{
}

// checks if map is closed and rectangular
void	validate_map_walls(char **map, const char *map_name)
{
	size_t x;
	size_t y;
	size_t rows_qnt;
	bool eql_rows;

	if (!map || !*map || !map_name)
		drop_error_ext(INVALID_POINTER, "Error: invalid pinter.", map);
	x = 0;                                   
	rows_qnt = count_map_rows(map_name) - 1; // remove it after (add third paramentr rows_qnt)
	while (map[x])
	{
		y = 0; // column
		if (x == 0 || x == rows_qnt)
		{
			eql_rows = (ft_strlen(map[0]) == ft_strlen(map[rows_qnt]));
			while (map[x][y])
			{
				if (!(map[x][y++] == '1') || !eql_rows)
					drop_error_ext(INVALID_MAP, "Error: map is invalid.", map);
			}
			x++;
		}
		else
		{
			eql_rows = (ft_strlen(map[0]) == ft_strlen(map[x]));
			if ((map[x][0] == '1' && map[x][ft_strlen(map[x]) - 1] == '1')
				&& eql_rows)
				x++;
			else
				drop_error_ext(INVALID_MAP, "Error: map is invalid.", map);
		}
	}
}

// map is rectangular
// a == c && b == d
// every row should be equel to each other sa well as calmn
// start and end of the row == 1;
// first/(last-1) row ==== 1111