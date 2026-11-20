*This project has been created as part of the 42 curriculum by rihammou.*

# ft_printf

## Description

ft_printf is a recreation of the standard C `printf()` function. The goal of this project is to understand variadic functions, formatted output, and how different data types can be handled and printed.

The function supports the following conversions:

- `%c` — Characters
- `%s` — Strings
- `%p` — Pointer addresses in hexadecimal
- `%d` / `%i` — Signed decimal integers
- `%u` — Unsigned decimal integers
- `%x` / `%X` — Lowercase and uppercase hexadecimal
- `%%` — Percent sign

The function also returns the total number of characters printed, matching the behavior of the original `printf()` for the supported conversions.

## Instructions

Clone the repository and compile the library using:

```bash
make
```

This generates `libftprintf.a`, a static library containing the ft_printf implementation and the required Libft functions. The library can then be linked to other C programs during compilation.

Other available Makefile commands:

- `make clean` — Removes object files.
- `make fclean` — Removes object files and compiled libraries.
- `make re` — Rebuilds the library from scratch.

## Algorithm and Data Structures

The implementation processes the format string character by character. Ordinary characters are printed directly, while a `%` indicates that the following character specifies a conversion.

A `va_list` is used to access the variable arguments passed to the function. Each supported conversion is handled by a dedicated helper, keeping the logic separated and easier to maintain.

For numerical conversions, the implementation uses division and modulo to extract individual digits. A recursive function handles the printing order, allowing the same logic to be reused for decimal and hexadecimal representations by changing the base string.

Pointer addresses are converted into hexadecimal, while signed and unsigned integers are handled according to their respective types.

The implementation mainly uses simple variables, pointers, and the variadic argument list rather than additional data structures. This approach keeps memory usage low and avoids unnecessary dynamic allocation.

Each printing function tracks the number of characters it outputs so that `ft_printf()` can return the total printed length.
