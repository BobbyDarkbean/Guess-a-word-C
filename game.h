#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <stdlib.h>

#define PL_COUNT 2
#define H_TURN 0
#define AI_TURN 1

typedef struct {
    const char *word;
    int movesToSolve;
    int solved;
} player_info;

void play_game();

#endif // GAME_H_INCLUDED
