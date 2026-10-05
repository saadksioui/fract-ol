srcs = main.c

objs = $(srcs:.c=.o)

fractol: $(objs)
	cc $(objs) -L/usr/include/minilibx-linux -lmlx -lXext -lX11 -lz -lm  -o $@

%.o: %.c
	cc -I/usr/include/minilibx-linux -c $< -o $@