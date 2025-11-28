# _printf – Custom printf implementation (Holberton School project)

## 📌 Description

Custom re-implementation of the C standard library `printf` function, written from scratch without using the standard I/O functions (`printf`, `puts`, etc.).  

Developed as part of the Holberton School low-level programming curriculum.

`_printf` prints formatted output to the standard output (`stdout`) using only the low-level `write` system call.  
It uses variadic arguments to handle a variable number of parameters and mimics the behavior of `printf` for a subset of format specifiers.

Repository name:

    holbertonschool-printf

---

## 📐 Prototype

    int _printf(const char *format, ...);

---

## 🧩 How it works

`_printf` takes:

* `const char *format` – the format string that contains:
    * normal characters, printed as-is
    * conversion specifiers introduced by `%`
* `...` – a variable number of arguments, each consumed by a conversion specifier in the format string.

Behavior (simplified):

1. If `format` is `NULL`, `_printf` returns `-1`.
2. The function iterates over `format` character by character.
3. If the current character is not `%`, it is printed directly.
4. If the current character is `%`, the next character determines the type of data to print (specifier).
5. For every valid specifier:
    * The corresponding argument is fetched from the `va_list`.
    * A dedicated handler function prints it.
    * The total count of printed characters is updated.
6. At the end, `_printf` returns the total number of characters printed, or `-1` on error.

---

## 🏗️ Supported format specifiers

### List

At the current stage, `_printf` supports:

* `%c` – Print a single character  
* `%s` – Print a string  
* `%%` – Print a literal percent sign  
* `%d` – Print a signed decimal integer  
* `%i` – Print a signed decimal integer  

For these supported specifiers, `_printf` aims to mimic the behavior of the standard `printf` as closely as possible.

(Additional specifiers may be implemented later in the project by completing the advanced tasks.)

### Summary table

| Specifier | Description            | Example call                               | Output        |
|----------:|------------------------|--------------------------------------------|---------------|
| `%c`      | Character              | `_printf("Char: %c\n", 'A');`              | `Char: A`     |
| `%s`      | String                 | `_printf("Str: %s\n", "Hello");`           | `Str: Hello`  |
| `%%`      | Literal percent sign   | `_printf("Percent: %%\n");`                | `Percent: %`  |
| `%d`      | Signed decimal integer | `_printf("Num: %d\n", 1024);`              | `Num: 1024`   |
| `%i`      | Signed decimal integer | `_printf("Num: %i\n", -42);`               | `Num: -42`    |

---

## 🎯 Return value

* On success: `_printf` returns the **total number of characters printed** (excluding the terminating null byte).
* On failure: `_printf` returns **`-1`**.

### Examples (return values)

    int len;

    len = _printf("Hello\n");
    /* Printed: "Hello\n" → len == 6 */

    len = _printf("Value: %d\n", 98);
    /* Printed: "Value: 98\n" → len equals the number of printed characters */

    len = _printf("Char: %c, Str: %s\n", 'A', "Hi");
    /* Printed: "Char: A, Str: Hi\n" → len == length of that full line */

Comparison with the standard `printf`:

    int len1 = _printf("Custom: %d\n", 42);
    int len2 = printf("Standard: %d\n", 42);
    /* For supported specifiers, len1 and len2 should usually match */

---

## 🧰 Requirements

* **Operating system**
    * Ubuntu 20.04 LTS

* **Compiler**
    * `gcc` with the following flags:
        * `-Wall`
        * `-Werror`
        * `-Wextra`
        * `-pedantic`
        * `-std=gnu89`

* **Allowed functions** (according to the project statement)
    * `write`
    * `malloc`
    * `free`
    * `va_start`
    * `va_end`
    * `va_copy`
    * `va_arg`

Any other standard library functions should not be used unless explicitly allowed by the project.

---

## ⚙️ Compilation

Basic compilation command:

    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c

With a custom `main.c` used for testing:

    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c main.c -o printf_test
    ./printf_test

---

## 🛠️ Usage

### Simple example

    #include "main.h"

    int main(void)
    {
        _printf("Hello, Holberton!\n");
        _printf("Character: %c\n", 'A');
        _printf("String: %s\n", "Sample");
        _printf("Number: %d\n", 1024);
        _printf("Percent: %%\n");
        return (0);
    }

Compilation and execution:

    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o printf_demo
    ./printf_demo

### More examples (per type)

Character:

    _printf("Char: %c\n", 'Z');
    /* Output: "Char: Z" followed by newline */

String:

    _printf("String: %s\n", "Holberton");
    /* Output: "String: Holberton" followed by newline */

Percent sign:

    _printf("Show percent: %%\n");
    /* Output: "Show percent: %" followed by newline */

Signed decimal:

    _printf("Positive: %d\n", 1234);
    /* Output: "Positive: 1234" followed by newline */

    _printf("Negative: %i\n", -987);
    /* Output: "Negative: -987" followed by newline */

Mixed:

    _printf("Name: %s, Grade: %d%%\n", "Alice", 95);
    /* Output: "Name: Alice, Grade: 95%" followed by newline */

---

## 📁 Project files

Example structure:

| File                 | Description                                                |
|----------------------|----------------------------------------------------        |
| `docs/flowchart.png` | Flowchart of the `_printf` algorithm                       |
| `_printf.c`          | Core `_printf` function, parser, and dispatcher            |
| `_putchar.c`         | Low-level function used by `_printf` and other printing functions  |
| `main.h`             | Header file with prototypes, macros, and typedefs          |
| `man_3_printf`       | Custom man page for `_printf`                              |
| `print_char.c`       | Handler for `%c`                                           |
| `print_int.c`        | Handler for `%d` / `%i`                                    |
| `print_percent.c`    | Handler for `%%` (prints a literal `%` character)                                            |
| `print_string.c`     | Handler for `%s`                                           |
| `.gitignore`         | Lists files and directories that Git should ignore         |
| `README.md`         | Project overview and descriptions for the custom `_printf` implementation.|
---

## 🔁 Flowchart

A high-level flowchart describes the internal logic of `_printf`:

1. Initialize `va_list` and counters.
2. Check if `format` is `NULL`.  
   * If `format == NULL`, return `-1`.
3. Loop through each character of `format`:
    * If the current character is **not** `%`:
        * Print it directly.
        * Increment the characters counter.
    * If the current character **is** `%`:
        * Look at the next character.
        * If it matches a valid specifier (`c`, `s`, `%`, `d`, `i`):
            * Call the corresponding handler function.
            * Add the number of printed characters to the counter.
        * Otherwise (undefined behavior in the standard):
            * Your implementation may return `-1` or handle it in a custom way.
4. Call `va_end` on the `va_list`.
5. Return the total number of printed characters.

If the flowchart is stored as an image, it can be referenced in the README:

    ![Printf flowchart](docs/flowchart.png)

---

## 📖 Man page

A custom manual page is provided for `_printf`.

To read it from the project directory:

    man ./man_3_printf

The man page includes:

* Function prototype  
* Description  
* List of supported specifiers  
* Return value  
* Examples of usage  

This allows `_printf` to be documented similarly to the standard `printf`.

---

## 🧪 Testing

### Betty style (Holberton C coding style)

Check that all `.c` and `.h` files comply with the Betty style:

    betty *.c *.h

### Valgrind (optional, for memory checks)

If dynamic memory is used (e.g. with `malloc`), Valgrind can be used to detect memory leaks:

    valgrind --leak-check=full ./printf_demo

### Manual tests

Example test ideas:

* Empty format string:

      _printf("");

* Format string with no specifiers:

      _printf("Just text, no specifiers\n");

* Multiple specifiers in one call:

      _printf("Char: %c, String: %s, Number: %d\n", 'A', "Holberton", 2025);

* Negative and large integers.

---

## ⚠️ Limitations

This is an educational project and the goal is not to fully reimplement every feature of `printf`.

Current implementation intentionally does **not** handle:

* Flags: `+`, `#`, `0`, `-`, space
* Field width
* Precision
* Length modifiers (`l`, `h`, etc.)
* All the advanced behaviors of the full standard `printf`

Behavior may therefore differ from the standard `printf` for unsupported or undefined cases.  
Only the specified and implemented conversion specifiers are guaranteed.

---

## 👥 Authors

* Antoine Gousset – GitHub: [Antgst](https://github.com/Antgst)  
* Djibril Niang – GitHub: [Tamsir-ui](https://github.com/Tamsir-ui)

