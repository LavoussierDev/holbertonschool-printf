# Printf Function

### Table of Contents
## Contributors
- https://github.com/LavoussierDev
- https://github.com/kriverao98

## Description
We took the premise of how printf functions works, and created the
function ourselves, there is no better learning experience, in this
repository you will also learn important fundementals.
/** Insert GIF Here **/

## Installation
- ``Git clone git@github.com:LavoussierDev/holbertonschool-printf.git``

/** Insert GIF Here **/

## How to use printf
<p>
1. Compile the cloned repository, compile it using
``gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c``
2. Make sure file in ends with .c extension.
3. Include "main.h" in said file & simply use \_putchar
like any other function.
</p>


## Restrictions & Challanges
### Restrictions
- Only Allowed to use 5 functions per file
- Global Variables were not allowed
- Header files must be guarded
- Cannot use switch cases

### Challanges
- Understanding the functions used & their use cases
  - ``write (man 2 write)
  - malloc (man 3 malloc)
  - free (man 3 free)
  - va_start (man 3 va_start)
  - va_end (man 3 va_end)
  - va_copy (man 3 va_copy)
  - va_arg (man 3 va_arg)``

- - -
**_Files_**:
- Header file (main.h)
	- Struct Parameters
	- Listed the prototypes
- Source file (printf.c)
	- printf function needs an a given argument for the input of the characters, format string, a variadic argument ..., it returns the number of characters given.
	- A function that will allocate the array of the structs.
	- A function that will free the array of the structs, within it needs a variable that will.
- Functions file (myfunctions.c)
	- Putchar function
	- Function that makes a copy of a string.
	- Function that writes string to stdout, variable is will grab the source of the string, it will return a string that's a copy of the source string
	- Function that can initialize all elements of a parameter struct, the pointer will list the parameters, and we must then have another variable that will format string,
- Numbers (Numerals.c)
	- Create a function that will return the absolute value of that integer, on top of that create another function to convert an integer to a string.
  - Aything else related to intengers.
- Test Directory
	- Testing the my own printf function to see if it works compared the built in printf function.
- Man Page File (Create man page using Pandoc or Simply doing it manually)
	- Creating a thorough Man page
