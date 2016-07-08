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

