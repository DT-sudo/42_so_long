/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_validation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dt <dt@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:41:49 by dtereshc          #+#    #+#             */
/*   Updated: 2025/07/12 16:31:27 by dt               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// validate file extetion
void	validation_map_name(const char *map_name)
{
	const char	*ext;

	if (!map_name)
		drop_error_ext(INVALID_MAP_NAME, "Error: Invalid map name", NULL);
	ext = ft_strrchr(map_name, '.');
	if (!ext || ft_strcmp(ext, ".ber") != 0)
		drop_error_ext(INVALID_MAP,
			"Error: Invalid file type: expected a .ber file", NULL);
}

// validate argc, argc
void	validate_arguments(int argc, char **argv)
{
	int	descriptor;

	if (argc < 2)
		drop_error_ext(EXIT_FAILURE, "Usage: ./so_long <map_file.ber>", NULL);
	else if (argc > 2)
		drop_error_ext(EXIT_FAILURE, "Error: Too many arguments provided.",
			NULL);
	validation_map_name(argv[1]);
	descriptor = open(argv[1], O_RDONLY);
	if (descriptor < 0)
		drop_error_ext(EXIT_FAILURE, "Error: Could not open map file.", NULL);
	close(descriptor);
}

// counts newline within the read buffer
int	catch_nl(char *buf, size_t size)
{
	int	n;
	int	c;

	n = 0;
	c = 0;
	while (n < size)
	{
		if (buf[n] == '\n')
			c++;
		n++;
	}
	return (c);
}

// counts
int	count_map_rows(const char *map_name)
{
	int		fd;
	int		rows_counted;
	char	buf[2048];
	size_t	bytes_read;
	char	last_char;

	last_char = '\0';
	rows_counted = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		drop_error_ext(FD_FAIL, "Error: File descriptor is not valid.", NULL);
	bytes_read = read(fd, buf, sizeof(buf));
	while (bytes_read > 0)
	{
		last_char = buf[bytes_read - 1];
		rows_counted += catch_nl(buf, bytes_read);
	}
	close(fd);
	if (rows_counted == 0 && last_char != '\0')
		drop_error_ext(INVALID_MAP, "Error: Invalid map format.", NULL);
	else if (last_char != '\n')
		rows_counted++;
	return (rows_counted);
}
