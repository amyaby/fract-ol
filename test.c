


int main()
{
    void *mlx;
    void *win;

    // Initialize MLX
    mlx = mlx_init();
    if (!mlx)
        return (1);

    // Create a 500x500 window
    win = mlx_new_window(mlx, 500, 500, "My MLX Window");
    if (!win)
        return (1);

    // Loop to keep the window open
    mlx_loop(mlx);

    return (0);
}

//cc main.c -Lminilibx-linux -lmlx -lX11 -lXext

