#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdbool.h>

#define FLAG_NONE   0x00
#define FLAG_PLUS   0x01
#define FLAG_MINUS  0x02
#define FLAG_ZERO   0x04
#define FLAG_SPACE  0x08
#define FLAG_HASH   0x10

int _printf(const char *format, ...);
bool is_valid_specifier(char c);
bool is_flag(char c);
void _write(char c);
int write_string(const char *s);
int process_specifier(char specifier, va_list args);
int custom_specifier(char specifier, va_list args);
const char *get_format_string(char specifier);
int handleUnsignedInt(va_list args, char specifier);
int handleSignedInt(va_list args, char specifier);
int handleCustomS(va_list args);
int binary_converter(va_list args);
char hex_to_char(int value);
int handleFlags(va_list args, const char *format);
int handleFlagX(unsigned int value, char specifier);
int extractFieldWidth(const char **format);
int extractPrecision(const char **format);
int reverse_string(const char *str);
int rot13_string(const char *str);
int process_format_string(const char *format, va_list args);

#endif
