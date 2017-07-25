# Variadic Functions

```c
va_list; //pointer to varaible arguments, cannot pass a pointer to va_list
va_start(va_list ap, paramN); // paramN precedes first variable parameter, enables access to variadic arguments
va_arg(ap, data_type); // interprets the next n bytes from stack according to data_type, each call points ap to the next arg
va_copy(dest, src); // copy va_list object
va_end(ap); // cleanup ap object
```

Variadic functions take a varaible number of arguments.  Declare variadic functions with ellipsis, `...` as the last parameter.  Use `#include <stdarg.h>` to access variadic arugments in the function body. The first argument in printf, the format string, provides a list of what variables to expect and count.  There is no type safety: if you pass an int like 1 when you thought you were passing a float like 1.0, results are undefined.

# Initializing Struct

```c
typedef struct {
int first, second;
double third;
gsl_vector *v;
} stype;

stype newvar = {3, 5, 2.3, a_vector};
```

# Dispatcher - array of function pointers


# printf error handling


# Conversions

Format tag prototype - `% flags width precision length specifier`

|specifier|Output|
|---------|------|
|s|string of chars|
|S|wide chars|
|p|pointer address|
|d|signed decimal integer|
|D|
|i|signed decimal integer|
|o|signed octal|
|O|
|u|unsigned decimal integer
|U|
|x|unsigned hexadecimal integer|
|X|unsigned hex int (captial letter)
|c|character|
|C|wide char|
|%%| print a percent sign|

|flags|Description|
|-----|-----------|
|-|left-justify within given field width|
|#|used with o,x or X specs to precede value with 0,0x or 0X|
|0|left pads number with 0s instead of spaces|
|' '|space precede a positive number|

|Minimum field-width|Description|
|-------------------|-----------|
|(number)| min number of printed chars, if num > value result is pad else if value > num not truncated

|Precision|Description|
|---------|-----------|
|.number|for int specs - min num of digits printed, if val < num then pad with leading 0s.  No value truncation. A precision 0 means no char printed for value 0.

|length|Description|
|------|-----------|
|hh|signed char for int specs, unsigned char for|
|h|short in or unsigned short int for int specs|
|l|long int or unsigned long int for int specs & wide for c / s specs|
|ll|converion spec applies to long long|
|j|conversion spec applies to int max_t|
|z|conversion spec applies to size_t|
