#include <stdio.h>
#define BOARD_SIZE 3

enum field {
    EMPTY = 0, X = 1, O = 2
};

enum game_state {
    ONGOING, X_WON, O_WON, DRAW
};

enum field board[BOARD_SIZE][BOARD_SIZE];
enum field current_player = X;

void draw_board() {
	char c[] = {' ', 'X', 'O'};


	printf("\e[1;1H\e[2J\n");
    for(int i=0; i < BOARD_SIZE; i++) {
        for(int j=0; j < BOARD_SIZE; j++) {
            printf(" %c ", c[board[i][j]]);
            if(j != BOARD_SIZE - 1) {
                printf("|");
            }
        }
        putchar('\n');
        if(i != BOARD_SIZE - 1) {
            printf("-----------");
            putchar('\n');
        }
    }
    putchar('\n');
}

enum game_state check_game_state() {
	for(int i=0; i<BOARD_SIZE; i++) {
		if(board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
			switch(board[i][0]) {
				case X:
					return X_WON;
				case O:
					return O_WON;
				default:
					break;
			}
		}
	}
	
	
	for(int i=0; i<BOARD_SIZE; i++) {
		if(board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
			switch(board[0][i]) {
				case X:
					return X_WON;
				case O:
					return O_WON;
				default:
					break;
			}
		}
	}
	
	if(board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
		switch(board[0][0]) {
			case X:
				return X_WON;
			case O:
				return O_WON;
			default:
				break;
		}
	}
	
	if(board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
		switch(board[0][2]) {
			case X:
				return X_WON;
			case O:
				return O_WON;
			default:
				break;
		}
	}
	
	for(int i=0; i < BOARD_SIZE; i++) {
		for(int j=0; j < BOARD_SIZE; j++) {
			if(board[i][j] == EMPTY) {	
				return ONGOING;
			}
		}
	}
	
	return DRAW;
}

void read_input() {
	char x, y;
	do {
		fputs("Enter your next move: ", stdout);
		scanf("%c%c", &x, &y);
		while(getchar() != '\n') {}

		x -= 'A';
		y -= '1';
		if (x < 0 || x > 2) {
			printf("WRONG INPUT\n");
			continue;
		}
		if (y < 0 || y > 2) {
			printf("WRONG INPUT\n");
			continue;
		}
		
		if(board[x][y] != EMPTY) {
			printf("WRONG INPUT: Space occupied\n");
			continue;
		}
		
		board[x][y] = current_player;
		current_player = (current_player == X)? O : X; 
		break;
	} while(1);
}

int main() {
	while(check_game_state() == ONGOING) {
	    draw_board();
		read_input();
	}
	
	switch(check_game_state()) {
		case X_WON:
			printf("X won!\n");
			break;
		case O_WON:
			printf("O won!\n");
			break;
		case DRAW:
			printf("Draw!\n");
			break;
		case ONGOING:
			printf("Ongoing!\n");
			break;
	}
    return 0;
}

