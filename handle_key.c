#include "fractal.h"


int handle_key(int keycode, void *param)
{
    (void)param;
    if (keycode == 65307) // Escape key
        exit(0);
    return (0);
}
int close_window(void *param)
{
    (void)param;
    exit(0);
    return (0);
}



