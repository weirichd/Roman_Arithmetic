.SUFFIXES:

CFLAGS=-std=c99 -Wall -Werror -O3

LIBS=check
LDFLAGS+=`pkg-config --cflags --libs $(LIBS)`

SOURCE=check_conversion.c
TESTS=$(wildcard *_tests.c)
HEADERS=../../src/conversion.h

TARGET=../$(BUILD_DIR)/$(patsubst check_%.c,test_%,$(SOURCE))

all: $(TARGET)

$(TARGET): $(SOURCE) $(TESTS) $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)
