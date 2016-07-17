.SUFFIXES:

CFLAGS=-std=c99 -Wall -Werror -O3

LIBS=check
LDFLAGS=-L../build -lromarth
LDFLAGS+=`pkg-config --cflags --libs $(LIBS)`

BUILD_DIR=build

SOURCES=check_romarth.c check_conversion.c

TARGETS=$(addprefix $(BUILD_DIR)/, $(patsubst check_%, test_%, $(SOURCES:.c=)))

all: $(BUILD_DIR) $(TARGETS)

$(BUILD_DIR):
	mkdir $@

$(BUILD_DIR)/test_romarth: addition_tests.c error_tests.c subtraction_tests.c ../src/romarth.c
$(BUILD_DIR)/test_conversion: roman_to_arabic_conversion_tests.c ../src/conversion.h

$(BUILD_DIR)/test_%: check_%.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

.PHONY: clean vars
.SILENT: clean 

clean:
	rm -rf $(BUILD_DIR)

vars:
	echo $(TARGETS)
