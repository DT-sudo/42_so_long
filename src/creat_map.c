/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:39:40 by dt                #+#    #+#             */
/*   Updated: 2025/07/12 16:34:36 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// allocates memory for the map
char	**malloc_map(int rows_qnt)
{
	char	**map;

	map = malloc((rows_qnt + 1) * sizeof(char *));
	if (!map)
		drop_error_ext(MAP_ALLOC_FAIL, "Error: Problem with map allocation.",
			map);
	return (map);
}

// gets the row of the map with get_next_line func
char	*get_map_row(int fd, char **map)
{
	char	*row;
	int		row_len;

	if (fd < 0)
		drop_error_ext(FD_FAIL, "Error: File descriptor is not valid.", map);
	row = get_next_line(fd);
	if (!row)
		drop_error_ext(INVALID_MAP, "Error: Invalid map format.", map);
	row_len = ft_strlen(row) - 1;
	if (row[row_len] == '\n' && (row_len + 1) > 0)
		row[row_len] = '\0';
	return (row);
}

// fills map with file's rows. Needs to be slightly changed
bool	add_rows(const char *map_name, char **map, int rows_qnt)
{
	int		fd;
	int		r;
	char	*row;

	r = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		drop_error_ext(FD_FAIL, "Error: File descriptor is not valid.", map);
	while (r < rows_qnt)
	{
		row = get_map_row(fd, map);
		if (!row)
			break ;
		map[r++] = row;
	}
	map[r] = NULL;
	close(fd);
	// ft_printf("Map is read. %d Rows\n", rows_qnt); ???
	return (true);
}

// creats allocated map
char	**creat_map(const char *map_name)
{
	char	**map;
	int		rows_qnt;
	bool	map_is_created;

	rows_qnt = count_map_rows(map_name);
	map = malloc_map(rows_qnt);
	if (!map)
		drop_error_ext(MAP_ALLOC_FAIL, "Error: Problem with map allocation.",
			map);
	add_rows(map_name, map, rows_qnt);
	return (map);
}

// get_next_line func needs to be checked !