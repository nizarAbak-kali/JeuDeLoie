CC=gcc
CFLAGS=-W -Wall
LIBS=-lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
EXEC=jeudeloie

all:$(EXEC)

jeudeloie:main.o 
	$(CC) $(CFLAGS) main.c -o jeudeloie $(LIBS)

main.o:main.c
	$(CC) $(CFLAGS) main.c $(LIBS)

clean:
	rm -rf *.o *~ 