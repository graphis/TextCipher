EXAMPLES = encrypt_file

$(EXAMPLES) :
	$(MAKE) --directory=$@ $(TARGET)

.PHONY:$(EXAMPLES)
all : $(EXAMPLES)

clean:
	TARGET=clean
	$(MAKE) all