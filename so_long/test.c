#include "mlx_mac/mlx.h"
#include <stdio.h>

int main(void)
{
    void *mlx;
    void *win;

    // Initialize mlx
    mlx = mlx_init();
    if (!mlx)
    {
        printf("Failed to initialize mlx\n");
        return (1);
    }

    // Create a window
    win = mlx_new_window(mlx, 800, 600, "Minimal mlx Example");
    if (!win)
    {
        printf("Failed to create window\n");
        return (1);
    }

    // Draw a red pixel at (10, 10)
    mlx_pixel_put(mlx, win, 10, 10, 0x00FF0000);

    // Enter the event loop to keep window open
    mlx_loop(mlx);

    return (0);
}
