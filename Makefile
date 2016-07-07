SUBDIRS=src test

.PHONY: clean $(SUBDIRS) tags run_test
.SILENT: clean

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

clean:
	$(foreach DIR, $(SUBDIRS), $(MAKE) -C $(DIR) $@;)

tags: 
	ctags -R --exclude=Makefile

run_test:
	test/build/test_romarth

test: src
