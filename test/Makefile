.SUFFIXES:

CFLAGS=-std=c99 -Wall -Werror -O3

LIBS=check
LDFLAGS=-L../build -lromarth
LDFLAGS+=`pkg-config --cflags --libs $(LIBS)`

BUILD_DIR=build

TARGET=$(BUILD_DIR)/test_romarth

SOURCES=check_romarth.c

OBJECTS=$(addprefix $(BUILD_DIR)/, $(SOURCES:.c=.o))

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir $@

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

$(BUILD_DIR)/%.o: %.c 
	$(CC) $(CFLAGS) -c -o $@ $< 

.PHONY: clean 
.SILENT: clean 

clean:
	rm -rf $(BUILD_DIR)
