#ifndef AI_H_INCLUDED
#define AI_H_INCLUDED

#include "game.h"

const char *pick_word_ai();
void turn_ai(player_info *pl_ai,
             player_info *pl_human);

void filter(const char *ptrn,
            int mt);

void allocate_sample_words_mem();
void free_sample_words_mem();
void initialize_sample_words();

#endif // AI_H_INCLUDED
