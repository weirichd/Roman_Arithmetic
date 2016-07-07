.SUFFIXES:

BUILD_DIR=../build

CFLAGS=-std=c99 -Wall -Werror -O3

TARGET=$(BUILD_DIR)/libromarth.a

SOURCES=romarth.c

OBJECTS=$(addprefix $(BUILD_DIR)/, $(SOURCES:.c=.o))

all: $(BUILD_DIR) $(TARGET) 

$(BUILD_DIR):   
	mkdir $@

$(TARGET): $(OBJECTS)
	ar rcs $@ $<

$(BUILD_DIR)/%.o: %.c %.h
	$(CC) $(CFLAGS) -c -o $(BUILD_DIR)/$@ $<

.PHONY: clean
.SILENT: clean

clean:
	rm -rf $(BUILD_DIR)
