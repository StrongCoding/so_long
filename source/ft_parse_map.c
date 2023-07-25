/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:09:00 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/25 11:13:34 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// return number of rows in the map
static int	ft_get_rows(char *file)
{
	int		fd;
	int		count_rows;
	char	*row;

	count_rows = 0;
	fd = open(file, O_RDONLY);
	if (fd < 1)
	{
		ft_printf("Error file!\n");
		return (-1);
	}
	row = get_next_line(fd);
	while (!(row == NULL))
	{
		count_rows++;
		free(row);
		row = get_next_line(fd);
	}
	free(row);
	close(fd);
	return (count_rows);
}

//returns 1 if map is valid
int	ft_check_map(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
		while (map[i][j] != NULL && map[i][j] != '\n')
			if (map[i][j] == WALL || map[i][j] == FLOOR || map[i][j] == COIN || map[i][j] == PLAYER || map[i][j] == MAP_EXIT)
				return (0);
	return (1);
}

// return 2D array, every line ends with \n or \0
char	**ft_parse_map(char *file, int rows)
{
	int		fd;
	char	*row;
	char	**map;
	int		i;

	i = -1;
	fd = open(file, O_RDONLY);
	if (fd < 1)
	{
		ft_printf("Error file!\n");
		return (NULL);
	}
	map = malloc((rows + 1) * sizeof(char *));
	while (++i <= rows)
		map[i] = get_next_line(fd);
	close(fd);
	return (map);
}

int	main(void)
{
	int		i;
	char	**string;

	i = ft_get_rows("../maps/map1.ber");
	printf("count rows:%i\n", i);
	string = ft_parse_map("../maps/map1.ber", i);
	i = -1;
	while (string[++i])
		printf("string[%i]: %s\n", i, string[i]);
}
