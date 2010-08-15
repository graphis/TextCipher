EXAMPLES = examples
SRC = src

src: 
	$(MAKE) --directory=$@ $(TARGET)

examples: $(EXAMPLES)

$(EXAMPLES): $(SRC)
	$(MAKE) --directory=$@ $(TARGET)

.PHONY: all $(SRC) $(EXAMPLES)
all: $(SRC) $(EXAMPLES)
