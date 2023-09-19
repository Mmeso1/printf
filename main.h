#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdbool.h>

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
int get_flags(const char *format, va_list args);
int reverse_string(const char *str);
int rot13_string(const char *str)
int process_format_string(const char *format, va_list args);

#endif
