.SUFFIXES:

CFLAGS=-std=c99 -Wall -Werror -O3

LIBS=check
LDFLAGS=-L../../build -lromarth
LDFLAGS+=`pkg-config --cflags --libs $(LIBS)`

SOURCE=check_romarth.c
TESTS=$(wildcard *_tests.c)
HEADERS=../../src/romarth.c ../../src/romarth.h

TARGET=../$(BUILD_DIR)/$(patsubst check_%.c,test_%,$(SOURCE))

all: $(TARGET)

$(TARGET): $(SOURCE) $(TESTS) $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)
