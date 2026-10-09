#include "fractol.h"
#include <mlx.h>

void my_mlx_put_pixel(t_data *data, int x, int y, int color) {
    char *dst;

    dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
    *(unsigned int*) dst = color;
}



int	close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->window);
    mlx_loop_end(vars->mlx);
	return (0);
}


void    plot(int *f(int x, int y), t_data *data, t_vars *vars) {
    
}



int main() {
    t_vars app;
    t_data img;

    app.mlx = mlx_init();
    app.width = 1920;
    app.height = 1080;

    app.window = mlx_new_window(app.mlx, app.width, app.height, "fractol");
    img.img_ptr = mlx_new_image(app.mlx, app.width, app.height);
    img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.size_line, &img.endian);
    my_mlx_put_pixel(&img, 5, 5, 0x00ff0000);
    mlx_put_image_to_window(app.mlx, app.window, img.img_ptr, 0, 0);
    mlx_hook(app.window, 17, 0, close, &app);
    mlx_loop(app.mlx);
}