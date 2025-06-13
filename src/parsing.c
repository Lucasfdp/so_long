/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 03:35:40 by luferna3          #+#    #+#             */
/*   Updated: 2025/06/08 03:35:41 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int handle_ber(char *str)
{
    int len;

    len = ft_int_strlen(str);
    if (len < 5)
        return (0);
    return (ft_strncmp((str + len - 4), ".ber", 4) == 0);
}

void    nwl_for_null(t_map *map)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (map->map[i])
    {
        j = 0;
        while (map->map[i][j])
        {
            if (map->map[i][j] == '\n')
                map->map[i][j] = '\0';
            j++;
        }
        i++;
    }
}

int prep_map(char **av, t_map *map)
{
    int fd;
    int i;
    int lines;
    map->map = NULL;

    i = 0;
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
        return (0);
    lines = count_lines(fd);
    close(fd);
    map->map = (char **)malloc(sizeof(char *) * (lines + 1));
    if (!map->map)
        return (0);
    fd = open(av[1], O_RDONLY);
    while ((map->map[i] = get_next_line(fd)) != NULL)
        i++;
    map->map[i] = NULL;
    nwl_for_null(map);
    map->height = i;
    map->width = ft_int_strlen(map->map[0]);
    close(fd);
    return (1);
}

int validate_pathing(t_map *map)
{
    char **map_cpy;
    int y;
    int x;
    int res;

    y = find_py(map->map, map->height, map->width);
    x = find_px(map->map, map->height, map->width);
    map_cpy = copy_map(map);
    flood_fill(map_cpy, y, x);
    res = check_ff(map_cpy, map->height, map->width);
    free_array(map_cpy, map->height);
    return (res);
}

int parse_map(t_map *map)
{
    if (!check_rectangle(map) || !check_valid_chars(map)
        || !check_char_count(map) || !validate_pathing(map))
    {    
        ft_printf("Error\nUnplayable map");
        return (0);
    }
    return (1);
}
