/* int	ft_check_view_up(int	**grid, int	x, int	y, int size)
{
	int	max;
	int	view;

	view = 1;
	max = grid[y][x];
	while (y <= 2)
	{
		if (ft_check_columns(grid, size) == 0)
			return (0);
		if (grid[y][x] > grid [y - 1][x])
			view++;
		if (grid[y - 1][x] > max)
		{
			view = 1;
			max = grid[x - 1][y];
		}
		y--;
	}
	if (view == grid[0][x])
		return (1);
	return (0);
}

int	ft_check_view_down(int	**grid, int	x, int	y, int size)
{
	int	max;
	int	view;

	view = 0;
	max = grid[y][x];
	while (y <= 2)
	{
		if (ft_check_columns(grid, size) == 0)
			return (0);
		if (grid[y][x] > grid [y + 1][x])
			view++;
		if (grid[y + 1][x] > max)
		{
			view = 1;
			max = grid[x - 1][y];
		}
		y--;
	}
} */

int	ft_check_view_line(int	**grid, int	x, int	y, int size)
{
	int	view;
	int	tmp;
	int	n;

	n = 1;
	view = 1;
	tmp = grid[y][1];
	while (grid[y][n] != 0 && n <= size + 1)
		if (grid[y][1] < grid[y][n++])
			view++;
	if (view <= grid[y][0])
		return (1);
	return (0);
}

/* int	ft_check_view_line(int	**grid, int	x, int	y)
{
	int	view;
	int	tmp;
	int	cond;

	view = 1;
	cond = grid[y][0];
	tmp = grid[y][x];
	while (x <= 2)
	{
		if (ft_check_line(grid, size) == 0)
			return (0);
		if (grid[y][x] > grid[y][x + 1])
			view++
		if
		x--;
	}
*/ 	