#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool mturn = true;

int grid[3][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};

void draw() {
    for (int i=0; i<3; i++) {
        printf("\t%d | %d | %d\n", grid[i][0], grid[i][1], grid[i][2]);
    }
}

int is_full() {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (grid[i][j] == 0) return 0;
        }
    }
    return 1;
}

int play(int c) {
    int row = (c-1) /3;
    int col = (c-1) % 3;
    int* val = &grid[row][col];
    if (*val == 0) {
        *val = mturn ? 1 : 2;
        mturn = !mturn;
        return 1;
    }
    return 0;
}

int check() {
    // player 1
    if (grid[0][0] == 1 && grid[0][1] == 1 && grid[0][2] == 1) return 1;
    if (grid[0][0] == 1 && grid[1][1] == 1 && grid[2][2] == 1) return 1;
    if (grid[0][0] == 1 && grid[1][0] == 1 && grid[2][0] == 1) return 1;
    
    if (grid[0][1] == 1 && grid[1][1] == 1 && grid[2][1] == 1) return 1;
    if (grid[1][0] == 1 && grid[1][1] == 1 && grid[1][2] == 1) return 1;
    if (grid[0][2] == 1 && grid[1][2] == 1 && grid[2][2] == 1) return 1;
    if (grid[2][0] == 1 && grid[2][1] == 1 && grid[2][2] == 1) return 1;

    // player 2
    if (grid[0][0] == 2 && grid[0][1] == 2 && grid[0][2] == 2) return 1;
    if (grid[0][0] == 2 && grid[1][1] == 2 && grid[2][2] == 2) return 1;
    if (grid[0][0] == 2 && grid[1][0] == 2 && grid[2][0] == 2) return 1;
    
    if (grid[0][1] == 2 && grid[1][1] == 2 && grid[2][1] == 2) return 1;
    if (grid[1][0] == 2 && grid[1][1] == 2 && grid[1][2] == 2) return 1;
    if (grid[0][2] == 2 && grid[1][2] == 2 && grid[2][2] == 2) return 1;
    if (grid[2][0] == 2 && grid[2][1] == 2 && grid[2][2] == 2) return 1;
}

int main() {
    bool running = true;
    while (running) {
        draw();
        if (is_full()) {
            printf("tie\n");
            running = false;
            break;
        }
        printf("turn: player %d\n", mturn ? 1 : 2);
        int c;
        printf("enter pos: ");
        if (!scanf("%d", &c)) {
            printf("please enter a number next time\n");
            running = false;
            break;
        }
        if (!play(c)) {
            printf("please choose empty slot\n");
            continue;
        }
        if (check()) {
            draw();
            if (!mturn) {
                printf("player 1 win\n");
            } else {
                printf("player 2 win\n");
            }
            running = false;
        }
    }
    return 0;
}