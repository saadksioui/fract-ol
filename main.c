#include "fractol.h"
#include <mlx.h>

void my_mlx_put_pixel(t_data *data, int x, int y, int color) {
    char *dst;

    dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
    *(unsigned int*) dst = color;
}


int mandelbrot(int px, int py) {
    float x = 0.0;
    float y = 0.0;

    int iter = 0;
    int max_iter = 1000;
    while (x*x + y*y <= 4 && iter < max_iter) {
        int xtemp = x*x - y*y + px;
        y = 2.0 * x * y + px;
        x = xtemp;
        iter++;
    }
    if (iter == max_iter)
        return 1;
    return 0;
}


t_coor screen_to_cartesian(t_vars *vars, int x, int y) {
    t_coor point;

    point.x = -2.0 + ((float)x / vars->width) * (0.47 + 2.0);
    point.y = -1.12 - ((float)y / vars->height) * (1.12 + 1.12);
    return point;
}


int	close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->window);
    mlx_loop_end(vars->mlx);
	return (0);
}


void    plot(int f(int x, int y), t_data *data, t_vars *vars) {
    int val;
    t_coor point;
    
    for (int x = 0; x < vars->width; x++) {
        for (int y = 0; y < vars->height; y++) {
            point = screen_to_cartesian(vars, x, y);
            val = f(point.x, point.y);
            if (val == 1)
                my_mlx_put_pixel(data, x, y, 0);
            else
                my_mlx_put_pixel(data, x, y, 0xfffff);
        }
    }
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
    // my_mlx_put_pixel(&img, 5, 5, 0x00ff0000);
    plot(mandelbrot, &img, &app);
    mlx_put_image_to_window(app.mlx, app.window, img.img_ptr, 0, 0);
    mlx_hook(app.window, 17, 0, close, &app);
    mlx_loop(app.mlx);
}