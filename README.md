# ✅ _printf Project — Holberton School

**📌 Description**

*The _printf project aims to recreate a simplified version of the standard C library function printf.*

*The goals of this project are to practice:*

*Handling strings and formatted output*

*Using variadic functions (va_list)*

*Modular program design in C*

*Clean architecture and documentation*

*Teamwork and Git versioning*

*This implementation supports multiple format, each handled by a dedicated function.*

**🏗️ Supported Format Specifiers**  
```
| Specifier   | Description                          |
| ----------- | ------------------------------------ |
| `%c`        | Prints a single character            |
| `%s`        | Prints a string                      |
| `%d` / `%i` | Prints a signed integer in base 10   |
| `%b`        | Prints an unsigned integer in binary |
```


## 
**📁 Project Structure**
### ordered

* main.h
* _putchar.c
* print_char.c
* print_string.c
* print_int.c
* print_binary.c
* get_print_func.c
* _printf.c
* man_3_printf

## Flowchart project

![This is an alt text.](docs/flowchart.png")


## 🧩 File Descriptions
#### ✅ _printf.c

* Main entry point 
* Iterates through the format string
* Detects % characters

* Calls the appropriate function

* Returns the total printed character count

✅ get_print_func.c

* Contains a structure mapping specifiers to functions

* Acts as a dispatcher

* Makes future extensions easier

✅ print_char.c

* Retrieves a character from va_list

* Prints it using _putchar

* Returns 1

✅ print_string.c

* Prints a string character by character

* Handles NULL by printing (null)

✅ print_int.c

* Converts a signed integer to decimal text

* Handles negative values

* Prints digits one by one

✅ print_binary.c

* Converts an unsigned integer to binary

* Prints the binary result without using printf

✅ _putchar.c

* Wrapper around the write system call

* Prints a single character

* Used by all print handlers

✅ main.h

* Contains all prototypes, includes, and data structures

* Central header for the entire project

✅ man_3_printf

* Manual page for the function

* Describes usage, behavior, and supported formats

## ⚙️ Compilation

To compile all source files:

        gcc -Wall -Wextra -Werror -pedantic *.c -o printf


✔ Follows Holberton requirements \
✔ Must compile with no warnings

Run the program:

        ./printf

✅ Usage Example
```
        _printf("Hello %s, number %d in binary is %b\n", "world", 5, 5);

        # Output:
        Hello world, number 5 in binary is 101
```

Return value:

* Total number of characters printed

## 🧰 Requirements

* OS: Ubuntu 20.04 LTS

* Compiler:  gcc

* Standard: ISO C90

* Forbidden: printf, puts, sprintf, etc.

* Allowed: write

* Code must be modular and readable

## 📖 Man Page Summary

**Name**

        _printf — formatted output function


**Prototype**

        int _printf(const char *format, ...);


**Description**

Prints formatted output based on the supported format specifiers.

Return Value

Returns the number of printed characters.

Returns -1 on error.

**Supported Specifiers**

%c, %s, %d, %i, %b

## Authors

You may be using [Markdown Live Preview](https://markdownlivepreview.com/).
