C = cc
CFLAGS = -Wall -Wextra -Iinclude
SRC = src/main.c 
OBJ = $(SRC:.c=.o)
OUT = bareml

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(OBJ) -o $(OUT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OUT)
