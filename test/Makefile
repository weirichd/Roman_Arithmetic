.SUFFIXES:

BUILD_DIR=build
SUBDIRS=romarth conversion validation

.PHONY: clean $(SUBDIRS) 

all: $(SUBDIRS)

$(SUBDIRS): $(BUILD_DIR)
	$(MAKE) -C $@ BUILD_DIR=$(BUILD_DIR)

$(BUILD_DIR):
	mkdir $@

clean:
	rm -rf $(BUILD_DIR)
