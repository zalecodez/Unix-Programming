CC = gcc
objects = copy/filecopy copy/copystd hole/holes time/bufftest

.PHONY: all
all: $(objects)

%: %.c
	$(CC) -o $@ $^

.PHONY: clean
clean: 
	rm $(objects)
