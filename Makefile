SUBDIRS = src examples

.PHONY: all $(SUBDIRS) clean

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) $(TARGET) -C $@
