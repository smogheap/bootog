CC = gcc
SDL2_LIB = $(shell sdl2-config --libs)
SDL2_INCLUDE = $(shell sdl2-config --cflags)

CCFLAGS = -Wall -c $(SDL2_INCLUDE)
LDFLAGS = $(SDL2_LIB) -lSDL2_image
BIN = bootog

all: $(BIN)

$(BIN): bootog.o
	$(CC) $< $(LDFLAGS) -o $@

%.o: src/%.c
	$(CC) $(CCFLAGS) $< -o $@

clean:
	rm *.o && rm $(BIN)
