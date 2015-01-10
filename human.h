#ifndef HUMAN_H_INCLUDED
#define HUMAN_H_INCLUDED

#include "game.h"

const char *pick_word_human();
void turn_human(player_info *pl_human,
                player_info *pl_ai);

int another_round();

#endif // HUMAN_H_INCLUDED
