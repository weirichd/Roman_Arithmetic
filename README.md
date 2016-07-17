# Roman Numeral Arithmetic Kata

This is my solution for the Roman Numeral Arithmetic Kata.  This kata was developed and tested under Ubuntu Linux v 14.04, which is the version I use at home :smile:

After building, you will have the following directory tree:
```
.
├── Makefile
├── README.md
├── build
│   ├── libromarth.a
│   └── romarth.o
├── src
│   ├── Makefile
│   ├── conversion.h
│   ├── numeral_map.h
│   ├── romarth.c
│   └── romarth.h
├── tags
└── test
    ├── Makefile
    ├── array_length_macro.h
    ├── build
    │   ├── test_conversion
    │   └── test_romarth
    ├── conversion
    │   ├── Makefile
    │   ├── arabic_to_roman_conversion_tests.c
    │   ├── check_conversion.c
    │   └── roman_to_arabic_conversion_tests.c
    ├── romarth
    │   ├── Makefile
    │   ├── addition_tests.c
    │   ├── check_romarth.c
    │   ├── error_tests.c
    │   └── subtraction_tests.c
    └── validation
        ├── Makefile
        ├── check_validation.c
        └── validation_tests.c
```

The library build/libromarth.a is the resultant target.

## Description of the library

The header file romarth.h provides two functions:

```c
char *roman_add(char *const sum, const size_t sum_size, const char *const summand1, const char *const summand2);
char *roman_subtract(char *const differene, const size_t difference_size, const char *const minuend, const char *const suptrahend);
```

These functions return their results, so you can conviently chain them if you wish:
```c
char sum1[50];
char sum2[50];

roman_add(sum2, 50, roman_add(sum1, 50, "V", "II"), "XXIII"); // sum2 holds the result of 5 + 3 + 23
```

You are free to use an input as an output as well:

```c
char iterator[50];

printf("Counting in Roman Numerals:\n");

for(iterator[0] = 'I'; strcmp(iterator, "XI") != 0; roman_add(iterator, iterator, "I")) {
    printf("%s\n", iterator);
}
```

The Roman arithmetic functions will return empty strings under any of the following conditions:

* The `sum_size` or `difference_size` is smaller than what is actually necessary to write the numeral result
```c
char sum[2];

roman_add(sum, 2, "I", "I");

printf("If you want to know what I + I is, allocate more memory! All I can see is: %s \n", sum);
```
* The difference would have been non-positive (when `suptrahend >= minuend`)
```c
char difference[50];

roman_subract(difference, 2, "V", "X");

printf("Romans didn't know how to write negative numbers so I think V - X gives: %s \n", difference);
```
* The sum is too large to be written (when `sum > 3999`)
```c
char sum[50];

roman_add(sum, 50, "MMM", "MMM");

printf("I can't even comprehend numbers that large... %s \n", sum);
```

* Any of the input strings are not valid roman numerals:
```c
char sum[50];
char difference[50];

roman_add(sum, 50, "Dinosaurs", "VVMIIXX");
roman_subtract(difference, 50, "IIIIIIIII", "VI");

printf("Nothing will be printed after this: %s %s\n", sum, difference);
```

## Requirements

You will need pkg-config installed in order to link without issues.  Run `sudo apt-get install pkg-config` from the command line if you do not have it.

To make the tags file you will need to have exuberant ctags. Run `sudo apt-get install exuberant-ctags` from the command like to install.

## To Build

Run `make` from the root directory.

## To run the tests

Run `make run_tests` from the root directory.

## To clean up the build files

Run `make clean` from the root directory.

# Write up

For this kata, I kept the following goals in mind:

* Test drive the code. Let the tests dictate how the code evolves. Do not predesign.
* Make the code as *simple* as possible, so that it is obvious what is going on at every step.

With this in mind, I tried to refactor whenever the algorithm started to look a little convoluted.

The development ended up following three phases: Initial development to satisfy the requirements, major refactor to make the numeral conversion algorithm simpler to follow, and a redevelopemt of subtraction.

Around commit #60, I commented out a majority of my tests and code in order to redo subtraction.  The reason for this was because, since subtraction and addition internally relied on the same conversion functions, once the II - I = I test was green **ALL** subtraction would work properly (except for error cases of course).  This, I felt, was a little scary since if at any time the library was swapped out (or refactored) for something else which was less tightly coupled between the addition and subtraction I still wanted the test suit to be robust.  This motivated the decision to test drive subtraction from the ground up, rather than just add a bunch of already passing tests after the fact.

## Changes after initial feed back

I made more changes to this project after receiving initila feedback.  It was suggested that the conversion functions be pulled out into a separate module.  However, the reviewer also commented positively on the fact that the non-arithmetic functions were static.  To satisfy both of these requirements, I pulled the static conversion functions out into a header file, which is then included by romarth.c. Once this header was pulled out, I felt that it would be appropriate to write tests for it.  To accomplish this, I proceeded similarly as with the subtraction implementation and commented out all functionality, adding failing tests and umcommenting as I went along.  I decided that the conversion tests should not be compiled with the tests for romarth, so I made a totally seperate test program for them.  The Makefiles were updated to account for this.

The reviewer commented that my library did not consider invalid roman numerals.  To account for this, I added another header file `validation.h' and test drove the development. It became clear that the simplest thing to do there would be to use regular expressions, so after implementing that I added a few more safety tests.

The `roman_add` and `roman_subtract` functions became too similar at this point, so I pulled out the functionality into a static `roman_operation` function and pass in a function pointer to do the actual math.
