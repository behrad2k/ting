CFLAGS = -Iinclude -march=raptorlake -mavx2 -mavx -msse4 -O0 -ftree-vectorize $(shell pkg-config sdl3 --cflags) #-O0 is smaller
CC = gcc
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: out

out: $(OBJ)
	$(CC) $< -o $@ -lSDL3

$(OBJ): $(SRC)
	$(CC) $< -c $(CFLAGS) -o $@
clean:
	rm -f $(OBJ)
