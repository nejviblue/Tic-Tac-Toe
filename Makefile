NAME=tictactoe
CC=cc
C_FLAGS=-Wall -Wextra -O2

all: $(NAME)
	

$(NAME):
	$(CC) $(CFLAGS) tictactoe.c -o $(NAME)

run: $(NAME)
	./$(NAME)

clean:
	rm $(NAME)

.PHONY: clean
