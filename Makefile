C = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = main.c $(shell find src -name '*.c')
OBJ = $(SRC:.c=.o)
OUT = atlas

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(OBJ) -o $(OUT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -lm

clean:
	rm -f $(OBJ) $(OUT)
