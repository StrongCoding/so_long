/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:09:00 by dnebatz           #+#    #+#             */
/*   Updated: 2023/08/03 17:21:41 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// return number of rows in the map
int	ft_get_rows(char *file)
{
	int		fd;
	int		count_rows;
	char	*row;

	count_rows = 0;
	fd = open(file, O_RDONLY);
	if (fd < 1)
	{
		ft_printf("Error\n");
		perror("");
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

//checks if there is one exit and at least 1 coin
int	ft_check_chars_count(char **map)
{
	int	c;
	int	j;
	int	e;
	int	i;

	i = -1;
	c = 0;
	j = 0;
	e = 0;
	while (map[++i])
	{
		while (map != NULL && map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] == EXIT)
				e++;
			if (map[i][j++] == COIN)
				c++;
		}
		j = 0;
	}
	if (e != 1 || c < 1)
		return (-1);
	return (1);
}

//returns 1 if all chars in map are valid and only 1 ghost
int	ft_check_chars(char **map)
{
	int	i;
	int	j;
	int	g;

	i = -1;
	j = 0;
	g = 0;
	while (map[++i])
	{
		while (map[i] != NULL && map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (!(map[i][j] == WALL || map[i][j] == GROUND || map[i][j] == COIN
				|| map[i][j] == GHOST || map[i][j] == EXIT
				|| map[i][j] == TRAP))
				return (-1);
			if (map[i][j] == GHOST)
				g++;
			j++;
		}
		j = 0;
	}
	if (ft_check_chars_count(map) < 0 || g != 1)
		return (-1);
	return (1);
}

//returns 1 if all chars in map are valid and all rows have same length
//error return -1 and give start position player
int	ft_check_map(char **map)
{
	if (ft_check_row_lengths(map) < 0)
	{
		ft_printf("Error\nMap is not rectrangular!\n");
		return (-1);
	}
	if (ft_check_chars(map) < 0)
	{
		ft_printf("Error\nBad char or bad char count in .ber file!\n");
		return (-1);
	}
	else if (ft_check_map_border(map) < 0)
	{
		ft_printf("Error\nMap is not sourrounded by walls!\n");
		return (-1);
	}
	else if (ft_check_path(map) < 0)
	{
		ft_printf("Error\nGame not solveable!\n");
		return (-1);
	}
	else
		return (1);
}

// return 2D array, every line ends with \n or \0
void	ft_parse_map(char *file, int rows, t_init *init)
{
	int		fd;
	char	**map;
	int		i;

	i = -1;
	fd = open(file, O_RDONLY);
	if (fd < 1)
		return ;
	map = malloc((rows + 1) * sizeof(char *));
	while (++i < rows)
		map[i] = get_next_line(fd);
	map[i] = NULL;
	close(fd);
	init->win_height = rows * 48;
	init->win_width = ft_check_row_lengths(map) * 48;
	if (ft_check_map(map) > 0)
		init->map = map;
}

// int	main(void)
// {
// 	int		i;
// 	char	**string;

// 	i = ft_get_rows("../maps/map1.ber");
// 	printf("count rows:%i\n", i);
// 	string = ft_parse_map("../maps/map1.ber", i);
// 	i = -1;
// 	if (string)
// 		while (string[++i])
// 			printf("string[%i]: %s\n", i, string[i]);
// 	else
// 		ft_printf("Map Error!\n");
// }