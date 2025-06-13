/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 03:35:22 by luferna3          #+#    #+#             */
/*   Updated: 2025/06/11 02:27:09 by luferna3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"

void    load_images(t_img *imgs, void *mlx)
{
    int i;
    int j;

    i = 0;
    j = 0;
    imgs->wall = mlx_xpm_file_to_image(mlx, "textures/wall.xpm", &i, &j);
    imgs->floor = mlx_xpm_file_to_image(mlx, "textures/floor.xpm", &i, &j);
    imgs->player = mlx_xpm_file_to_image(mlx, "textures/player.xpm", &i, &j);
    imgs->exit = mlx_xpm_file_to_image(mlx, "textures/exit.xpm", &i, &j);
    imgs->collect = mlx_xpm_file_to_image(mlx, "textures/collectible.xpm", &i, &j);
}

void	put_tile(void *mlx, void *win, t_img *imgs, char tile, int x, int y)
{
	int px = x * 32;
	int py = y * 32;

	if (tile == '1')
		mlx_put_image_to_window(mlx, win, imgs->wall, px, py);
	else if (tile == '0')
		mlx_put_image_to_window(mlx, win, imgs->floor, px, py);
	else if (tile == 'P')
	{
		mlx_put_image_to_window(mlx, win, imgs->floor, px, py);
		mlx_put_image_to_window(mlx, win, imgs->player, px, py);
	}
	else if (tile == 'C')
	{
		mlx_put_image_to_window(mlx, win, imgs->floor, px, py);
		mlx_put_image_to_window(mlx, win, imgs->collect, px, py);
	}
	else if (tile == 'E')
	{
		mlx_put_image_to_window(mlx, win, imgs->floor, px, py);
		mlx_put_image_to_window(mlx, win, imgs->exit, px, py);
	}
}

void	draw_map(t_map *map, void *mlx, void *win, t_img *imgs)
{
	for (int y = 0; y < map->height; y++)
	{
		for (int x = 0; x < map->width; x++)
		{
			put_tile(mlx, win, imgs, map->map[y][x], x, y);
		}
	}
}
