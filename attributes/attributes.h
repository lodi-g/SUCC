#pragma once


// Declare a function as not returning
// eg calling abort() or exit()
#define __noreturn __attribute__((noreturn))


// Declare a function as using a printf like format string
// First argument is the format string, second arg is the first vararg
#define __printf_attr(fidx, farg) __attribute__((format(printf, fidx, farg)))
