# Roman Numeral Arithmetic Kata

This is my solution for the Roman Numeral Arithmetic Kata.

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
## Requirements

You will need pkg-config installed in order to link without issues.  Run `sudo apt-get install pkg-config` from the command line if you do not have it.

## To Build

Run `make` from the root directory.

## To run the tests

Run `make run_tests` from the root directory.

## To clean up the build files

Run `make clean` from the root directory.

