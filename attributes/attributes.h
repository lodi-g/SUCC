#pragma once


// Declare a function as not returning
// eg calling abort() or exit()
#define __noreturn __attribute__((noreturn))


// Declare a function as using a printf like format string
// First argument is the format string, second arg is the first vararg
#define __printf_attr(fidx, farg) __attribute__((format(printf, fidx, farg)))


// Declares a function as being a constructor or destructor
// These functions will be called automatically before the flow enters main() and after main() has completed
#define __constructor __attribute__((constructor))
#define __destructor __attribute__((destructor))

// Defines a priority in constructors and destructors
#define __constructor__(p) __attribute__((constructor(p)))
#define __destructor__(p) __attribute__((destructor(p)))
