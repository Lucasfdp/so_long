#include "so_long.h"

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
