#ifndef ROMARTH_H
#define ROMARTH_H

#include <stddef.h> /* For size_t */

char *roman_add(char *const sum, const size_t sum_size, const char *const summand1, const char *const summand2);
char *roman_subtract(char *const differene, const size_t difference_size, const char *const minuend, const char *const suptrahend);

#endif /* ROMARTH_H */
