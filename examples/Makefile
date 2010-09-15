EXAMPLES = encrypt_file

.PHONY: all $(EXAMPLES) clean
all : $(EXAMPLES)

$(EXAMPLES) :
	$(MAKE) $(TARGET) -C $@

clean: $(EXAMPLES)