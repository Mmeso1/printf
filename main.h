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

#endif
