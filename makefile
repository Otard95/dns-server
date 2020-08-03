.PHONY: clean, mrproper, initobjdir
CC = gcc
CFLAGS = -g -Wall
OBJ = $(shell find ./src -name "*.c" | sed "s/\.c/\.o/" | sed -e "s/\.\/src\//obj\//")
SRCSTRUCTURE = $(shell find ./src -type d | sed "s/src/obj/")

all: mrproper initobjdir dns

test:
	@echo $(SRCSTRUCTURE)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

dns: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $+

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f dns

initobjdir:
	mkdir -p $(SRCSTRUCTURE)

