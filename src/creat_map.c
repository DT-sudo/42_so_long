/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:39:40 by dt                #+#    #+#             */
/*   Updated: 2025/07/15 16:46:00 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*get_row(int fd, char **map)
{
	int		row_len;
	char	*row;

	if (!map)
		drop_error_ext(INVALID_POINTER, "Error: invalid pinter.\n", map);
	if (fd < 0)
		drop_error_ext(FD_FAIL, "Error: File descriptor is not valid.\n", map);
	row = get_next_line(fd);
	if (!row)
		return NULL;
	row_len = ft_strlen(row);
	if (row_len > 0 && row[row_len - 1] == '\n')
		row[row_len - 1] = '\0';
	return (row);
}

char	**malloc_map(int lines)
{
	char	**res;

	res = malloc((lines + 1) * sizeof(char *));
	if (!res)
		drop_error_ext(MAP_ALLOC_FAIL, "Error: Problem with map allocation.\n",
			NULL);
	return (res);
}

bool	add_rows(t_game_map *game, int rows_qnt)
{
	int		fd;
	int		r;
	char	*row;

	if (!game || !game->map || !game->map_name)
		drop_error_ext(INVALID_POINTER, "Error: invalid pinter.\n", game->map);
	r = 0;
	fd = open(game->map_name, O_RDONLY);
	if (fd < 0)
		drop_error_ext(FD_FAIL, "Error: File descriptor is not valid.\n", game->map);
	while (r < rows_qnt)
	{
		row = get_row(fd, game->map);
		if (!row)
			break ;
		game->map[r++] = row;
	}
	game->map[r] = NULL;
	close(fd);
	if (r != rows_qnt)
		drop_error_ext(INVALID_MAP, "Error: Map has inconsistent row count.\n", game->map);
	return (true);
}

int	count_map_rows(const char *map_name)
{
	int		fd;
	int		rows_counted;
	char	buf[2048];
	ssize_t	bytes_read;
	char	last_char;

	last_char = '\0';
	rows_counted = 0;
	if (!map_name)
		drop_error_ext(INVALID_POINTER, "Error: invalid pinter.\n", NULL);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		drop_error_ext(FD_FAIL, "Error: File descriptor is not valid.\n", NULL);
	bytes_read = read(fd, buf, sizeof(buf));
	while (bytes_read > 0)
	{
		last_char = buf[bytes_read - 1];
		rows_counted += catch_nl(buf, bytes_read);
		bytes_read = read(fd, buf, sizeof(buf));
	}
	close(fd);
	if (rows_counted == 0 && last_char != '\0')
		drop_error_ext(INVALID_MAP, "Error: Invalid map format.\n", NULL);
	else if (last_char != '\n')
		rows_counted++;
	return (rows_counted);
}

char	**creat_map(t_game_map *game)
{
	char	**map;
	int		rows_qnt;

	if (!game || !game->map_name)
		drop_error_ext(INVALID_POINTER, "Error: invalid pinter.\n", NULL);
	rows_qnt = count_map_rows(game->map_name);
	map = malloc_map(rows_qnt);
	if (!map)
		drop_error_ext(MAP_ALLOC_FAIL, "Error: Problem with map allocation.\n",
			NULL);
	game->map = map;
	add_rows(game, rows_qnt);
	return (map);
}
