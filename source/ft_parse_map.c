/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:09:00 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/24 21:44:22 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**ft_parse_map(char *file)
{
	int		fd;
	int		count_rows;
	t_list	*rows;
	char	*row;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (NULL);
	rows = ft_lstnew(get_next_line(fd));
	while (ft_lstadd_back(&rows, ft_lstnew(get_next_line(fd))))
		count_rows++;
	printf("content %s\n", rows->content);
}
