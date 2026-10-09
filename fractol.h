#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct s_coor
{
	float	x;
	float	y;
}			t_coor;

typedef struct s_data
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}			t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*window;
	int		width;
	int		height;
}			t_vars;

#endif