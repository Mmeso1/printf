#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdbool.h>

int _printf(const char *format, ...);
bool is_valid_specifier(char c);
void _write(char c);
int write_string(const char *s);
int process_specifier(char specifier, va_list args);
int custom_specifier(char specifier, va_list args);
const char *get_format_string(char specifier);
int handleUnsignedInt(va_list args, char specifier);
int handleSignedInt(va_list args, char specifier) ;
int process_format_string(const char *format, va_list args);

/**
 * Prototypes of functions written by Sampson
 */

int print_char(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size);

#endif
