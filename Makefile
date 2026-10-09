srcs = main.c

objs = $(srcs:.c=.o)

fractol: $(objs)
	cc $(objs) -L./minilibx-linux -lmlx -lXext -lX11 -lz -lm -o $@

%.o: %.c fractol.h
	cc -I./minilibx-linux -c $< -g -o $@

clean:
	rm -rf $(objs)

re:clean fractol
	
	