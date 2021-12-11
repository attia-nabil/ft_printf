# ft_printf

This project is a copy of the original printf function of C langage.

Ft_printf (42cursus) 2021-2022

- Actual Status : finished.
- Result        : 100%
- Observations : NULL

![Capture](https://user-images.githubusercontent.com/78090806/145681644-f6ef6132-3b58-4438-9ab5-7580c18e4ee1.PNG)

## Features

Supports all these converters, flags and modifiers:

 Type        | Name
------------ | -------------------------------------------------------------------------------
 Converters  |  %d / %s / %p / %i / %u / %x / %X / %c/ %%
 Flags       |  * / 0 / - / .


## Compilation

Run `make` command to compile the libftprintf library.

## Usage

Compile your project with libftprintf.a.
Don't forget to include "ft_printf.h"

To compile with the repository main:
```
gcc -Wall -Werror -Wextra main.c libftprintf.a 
```

### Some examples
```C
int main(void)
{
    ft_printf("26----------------------\n");
    printf("%d\n",    printf("   printf |%-8.6d|%-8.6d|\n", 1025, -1025));
    printf("%d\n", ft_printf("ft_printf |%-8.6d|%-8.6d|\n", 1025, -1025));
    ft_printf("26----------------------\n");
    printf("%d\n",    printf("   printf |%-15.8d|\n", 15));
    printf("%d\n", ft_printf("ft_printf |%-15.8d|\n", 15));
    ft_printf("26----------------------\n");
    printf("%d\n",    printf("|%-20.8d|\n", 15));
    printf("%d\n", ft_printf("|%-20.8d|\n", 15));
    ft_printf ("111-----------------------------------\n");
    printf("%d\n",    printf("   printf |%0*d|%0*d|\n",  -3, 10012, -3, -10012));
    printf("%d\n", ft_printf("ft_printf |%0*d|%0*d|\n",  -3, 10012, -3, -10012));
    ft_printf ("119-----------------------------------\n");
    printf("%d\n",    printf("   printf |%-*d|%-*d|\n",  5, 10012, 5, -10012));
    printf("%d\n", ft_printf("ft_printf |%-*d|%-*d|\n",  5, 10012, 5, -10012));
    return (0);
}
```
### Output:
```Shell
./a.out 
26------------------------------------
   printf |001025  |-001025 | 30
ft_printf |001025  |-001025 | 30
26------------------------------------
   printf |00000015       | 28
ft_printf |00000015       | 28
26------------------------------------
|00000015            | 23
|00000015            | 23
111-----------------------------------
   printf |10012|-10012| 25
ft_printf |10012|-10012| 25
119-----------------------------------
   printf |10012|-10012| 25
ft_printf |10012|-10012| 25
```

[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/built-with-love.svg)](https://forthebadge.com)

This is my ft_printf project from the 42 cursus (1337),
need help:
nattia@student.1337.ma
