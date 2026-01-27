*This project has been created as part of the 42 curriculum by hilyas.*

# ft_printf - Custom printf Implementation

## Description

This project implements a custom version of the C standard library's `printf()` function. The goal is to recreate a subset of the original `printf()` functionality from scratch, providing hands-on experience with variadic functions, formatted output handling, and type conversions in C.

The implementation supports the following format specifiers:
- `%c` - Print a single character
- `%s` - Print a string
- `%p` - Print a pointer address in hexadecimal format
- `%d` / `%i` - Print a signed decimal integer
- `%u` - Print an unsigned decimal integer
- `%x` - Print a number in lowercase hexadecimal
- `%X` - Print a number in uppercase hexadecimal
- `%%` - Print a percent sign

This implementation does not include buffer management like the original `printf()` and focuses on the core conversion logic.

## Instructions

### Compilation

To compile the library, run:

```bash
make
```

This will create the static library `libftprintf.a`.

### Usage

Include the header file in your C program:

```c
#include "ft_printf.h"
```

Link the library during compilation:

```bash
cc your_program.c -L. -lftprintf -o your_program
```

### Example

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "world");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    return (0);
}
```

### Makefile Commands

- `make` or `make all` - Compile the library
- `make clean` - Remove object files
- `make fclean` - Remove object files and the library
- `make re` - Recompile everything from scratch

## Resources

### Documentation References
- C Standard Library Documentation - `printf()` specification
- `stdarg.h` - Variadic functions in C
- 42 Network Subject - ft_printf project requirements

### Algorithm and Data Structure Choices

The implementation uses a modular approach with separate functions for each conversion type:

1. **Main Function** (`ft_printf`):
   - Parses the format string character by character
   - Uses variadic functions (`va_list`, `va_start`, `va_arg`, `va_end`)
   - Dispatches to appropriate handler functions for format specifiers

2. **Conversion Functions**:
   - **Character (`%c`)**: Direct write using `write()` system call
   - **String (`%s`)**: Iterates through string characters, handles NULL case
   - **Pointer (`%p`)**: Converts memory address to hexadecimal with `0x` prefix
   - **Signed Integers (`%d`, `%i`)**: Handles negative numbers and converts to decimal
   - **Unsigned Integers (`%u`)**: Handles only positive numbers
   - **Hexadecimal (`%x`, `%X`)**: Converts to base-16 with case sensitivity

3. **Recursive Approach**:
   - Integer conversions use recursion to handle digits in reverse order
   - Each recursive call processes one digit and returns the count
   - Base cases handle single digits directly

4. **Error Handling**:
   - Checks for write errors at the beginning of `ft_printf`
   - Returns -1 on write failure as per standard behavior
   - Handles NULL string pointer gracefully

5. **Memory Management**:
   - No dynamic memory allocation used
   - All operations use stack memory
   - Avoids buffer overflow by writing directly to output

This design was chosen for its simplicity, clarity, and adherence to the original `printf()` behavior while working within the project constraints.

### AI Usage Statement

AI assistance was used in the following aspects of this project:

1. **Code Refactoring**: To create alternative implementations of functions while maintaining identical behavior, helping to understand different approaches to solving the same problem.

2. **Documentation**: For structuring and formatting the README file according to 42 standards.

3. **Makefile Optimization**: For suggesting improvements to the build system while maintaining compatibility with project requirements.

All core algorithmic decisions, logic implementation, and final code validation were performed by the student. The AI served as a tool for exploring alternative implementations and improving documentation clarity.

## Project Structure

- `ft_printf.c` - Main printf function with format parsing
- `ft_putchar.c` - Character output function
- `ft_putstr.c` - String output function
- `ft_putnbr.c` - Signed integer output function
- `ft_putunsigned.c` - Unsigned integer output function
- `ft_puthexnbr.c` - Hexadecimal output function
- `ft_putadress.c` - Pointer address output function
- `ft_printf.h` - Header file with function prototypes
- `Makefile` - Build system configuration
```
