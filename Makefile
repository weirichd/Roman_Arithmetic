SUBDIRS=src test

.PHONY: clean $(SUBDIRS) tags run_tests
.SILENT: clean

TESTS=$(wildcard test/build/test_*)

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

clean:
	$(foreach DIR, $(SUBDIRS), $(MAKE) -C $(DIR) $@;)

tags: 
	ctags -R --exclude=Makefile

run_tests:	
	test/build/test_validation
#	$(foreach TEST, $(TESTS), $(TEST);)
