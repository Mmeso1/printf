#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

bool is_valid_specifier(char c);
void write(char c);
int write_string(const char *s)
int process_specifier(char specifier, va_list args);
int process_format_string(const char *format, va_list args);

#endif
