#include "minilibx-linux/mlx.h"

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	win = mlx_new_window(mlx, 800, 600, "MiniLibX Window");
	mlx_loop(mlx);
	return (0);
}
