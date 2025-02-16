#include <unistd.h>
#include <string.h>
#include <stdlib.h>

// Function to validate if input is a float
int is_valid_float(char *str)
{
    char *endptr;
    strtod(str, &endptr);
    return (*endptr == '\0');
}

// Main parsing function
int fractol(int argc, char **argv)
{
    // Case when there are two arguments (mandelbrot or burning_ship)
    if (argc == 2)
    {
        if (strcmp(argv[1], "mandelbrot") != 0 && strcmp(argv[1], "burning_ship") != 0)
        {
            write(1, "___must be like this: ./a.out mandelbrot or ./a.out burning_ship___\n", 71);
            return 0;
        }
    }

    // Case when there are four arguments (julia with two float parameters)
    else if (argc == 4)
    {
        if (strcmp(argv[1], "julia") != 0)
        {
            write(1, "___must be like this: ./a.out julia <real> <imaginary>___\n", 58);
            return 0;
        }
        else if (!is_valid_float(argv[2]) || !is_valid_float(argv[3]))
        {
            write(1, "___Both parameters for julia must be valid floating-point numbers___\n", 71);
            return 0;
        }
        // Now we can safely assign the real and imaginary parts
        double real = atof(argv[2]);
        double imaginary = atof(argv[3]);
        // Use real and imaginary as needed
    }

    // If arguments are not valid for either case
    else
    {
        write(1, "___Invalid number of arguments___\n", 34);
        return 0;
    }

    // Return success if everything is correct
    return 1;
}
