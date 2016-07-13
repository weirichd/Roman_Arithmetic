# Roman Numeral Arithmetic Kata

This is my solution for the Roman Numeral Arithmetic Kata.  This kata was developed and tested under Ubuntu Linux v 14.04, which is the version I use at home :smile:

After building, you will have the following directory tree:

```
.
├── build
│   ├── libromarth.a
│   └── romarth.o
├── Makefile
├── README.md
├── src
│   ├── Makefile
│   ├── romarth.c
│   └── romarth.h
├── tags
└── test
    ├── addition_tests.c
    ├── build
    │   ├── check_romarth.o
    │   └── test_romarth
    ├── check_romarth.c
    ├── error_tests.c
    ├── Makefile
    └── subtraction_tests.c
```

The library build/libromarth.a is the resultant target.

## Description of the library

The header file romarth.h provides two functions:

```c
char *roman_add(char *sum, size_t sum_size, char *summand1, char *summand2);
char *roman_subtract(char *difference, size_t difference_size, char *minuend, char *suptrahend);
```

These functions return their results, so you can conviently chain them if you wish:
```c
char sum1[50];
char sum2[50];

roman_add(sum2, 50, roman_add(sum1, 50, "V", "II"), "XXIII"); // sum2 holds the result of 5 + 3 + 23
```

## Requirements

You will need pkg-config installed in order to link without issues.  Run `sudo apt-get install pkg-config` from the command line if you do not have it.

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

The development ended up following three phases: Initial development to satisfy the requirements, major refactor to make the numeral conversion algorithm simpler to follow, and a redevelopemt of subtraction.  Around commit #60, I commented out a majority of my tests and code in order to redo subtraction.  The reason for this was because, since subtraction and addition internally relied on the same conversion functions, once the II - I = I test was green **ALL** subtraction would work properly (except for error cases of course).  This I felt was a little scary, since if at any time the library was swapped out for something else which was less tightly coupled between the addition and subtraction, I still wanted the test suit to be robust.  Thsi motivated the decision to test drive subtraction from the ground up, rather than just add a bunch of already passing tests after the fact.
