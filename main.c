#include <mlx.h>

int main() {
    void *said = mlx_init();
    void *window = mlx_new_window(said, 1000, 1000, "Said haywli s7i7");
    int t = mlx_loop(said);
}