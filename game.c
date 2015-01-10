#include <stdio.h>
#include <stdlib.h>
#include "word.h"
#include "dict.h"
#include "ai.h"
#include "human.h"

#include "game.h"

void play_game()
{
    game_status gs;
    int turn;
    player_info pl[PL_COUNT];
    void (*make_move[PL_COUNT])(player_info *, player_info *, game_status *);

    make_move[H_TURN] = turn_human;
    make_move[AI_TURN] = turn_ai;

    allocate_sample_words_mem(pick_dict_size());

    printf("%d words.\n", w_dict_size());

    turn = rand() % PL_COUNT;
    while (1)
    {
        putchar('\n');

        initialize_sample_words();

        pl[H_TURN].movesToSolve = 0;
        pl[AI_TURN].movesToSolve = 0;

        pl[H_TURN].word = pick_word_human();
        pl[AI_TURN].word = pick_word_ai();

        pl[H_TURN].solved = 0;
        pl[AI_TURN].solved = 0;

        gs = RUNNING;

        while (!pl[turn].solved || !pl[turn ^ 1].solved)
        {
            if (!pl[turn].solved)
                (*make_move[turn])(&pl[turn], &pl[turn ^ 1], &gs);
            if (!pl[turn ^ 1].solved)
                (*make_move[turn ^ 1])(&pl[turn ^ 1], &pl[turn], &gs);
        }

        if (pl[H_TURN].movesToSolve < pl[AI_TURN].movesToSolve)
            puts("You win.");
        else if (pl[H_TURN].movesToSolve > pl[AI_TURN].movesToSolve)
            puts("Computer win.");
        else
            puts("Draw.");

        turn ^= 1;

        if (!another_round())
            break;
    }

    free_sample_words_mem();
}
