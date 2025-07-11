/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_validation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtereshc <dtereshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:41:49 by dtereshc          #+#    #+#             */
/*   Updated: 2025/07/10 20:32:18 by dtereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// validate file extetion
int		validation_filename(const char *filename)
{
	const char	*ext;

	if (!filename)
		return (0);
	ext = ft_strrchr(filename, '.');
	if (!ext || ft_strcmp(ext, ".ber") != 0)
	{
		ft_printf("Invalid file type: expected a .ber file\n");
		return (0);
	}
	return (1);
}

// validate argc, argc
void	validate_arguments(int argc, char **argv)
{
	int	descriptor;

	if (argc < 2)
	{
		ft_printf("Usage: ./so_long <map_file.ber>\n");
		exit(EXIT_FAILURE);
	}
	else if (argc > 2)
	{
		ft_printf("Error: Too many arguments provided.\n");
		exit(EXIT_FAILURE);
	}
	if (!validation_filename(argv[1]))
		exit(EXIT_FAILURE);
	descriptor = open(argv[1], O_RDONLY);
	if (descriptor == -1)
	{
		ft_printf("Error: Could not open map file.\n");
		exit(EXIT_FAILURE);
	}
	close(descriptor);
}

// counts neline within the read buffer 
int		count_buf_nl(char *buf, int size)
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
int		count_map_rows(char *fname)
{
	int fd;
	int c;
	char buf[2048];
	ssize_t bytes_read;
	char last_char;

	c = 0;
	last_char = '\0';
	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (-1);
	bytes_read = read(fd, buf, sizeof(buf));
	while (bytes_read > 0)
	{
		last_char = buf[bytes_read - 1];
		c += count_buf_nl(buf, bytes_read);
	}
	close(fd);
	if (c == 0 && last_char != '\0')
		c = 1;
	else if (last_char != '\n')
		c++;
	return (c);
}

// step, map_e, map_p, coin, 
// need_coin, exit, start, map