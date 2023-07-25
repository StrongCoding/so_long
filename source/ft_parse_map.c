/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:09:00 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/25 21:20:04 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//check row lengths, if not all same return -1 else return the length for window
int	ft_check_row_lengths(char **map)
{
	int	i;
	int	len;

	i = 0;
	if (!map)
		return (-1);
	len = ft_strlen_s(map[i++]);
	while (map[i])
	{
		if (!(len == ft_strlen_s(map[i++])))
			return (-1);
	}
	printf("return len: %i\n", len);
	return (len);
}

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

//returns 1 if all chars in map are valid
int	ft_check_map(char **map)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (map[++i])
	{
		while (map[i] != NULL && map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (!(map[i][j] == WALL || map[i][j] == GROUND || map[i][j] == COIN
				|| map[i][j] == GHOST || map[i][j] == EXIT))
				return (0);
			j++;
		}
		j = 0;
	}
	if (ft_check_row_lengths(map) > 0)
		return (1);
	else
		return (-1);
}

// return 2D array, every line ends with \n or \0
char	**ft_parse_map(char *file, int rows, t_init *init)
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
	printf("check map\n");
	init->win_height = rows * 48;
	init->win_width =  ft_check_row_lengths(map) * 48;
	if (ft_check_map(map) > 0)
		return (map);
	return (NULL);
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
