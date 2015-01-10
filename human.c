#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "word.h"
#include "dict.h"

#include "human.h"

const char *pick_word_human_helper(int pick, const char *prompt);

const char *pick_word_human()
{
    return pick_word_human_helper(1, "Pick a word: ");
}

void turn_human(player_info *pl_human, player_info *pl_ai)
{
    int cmp;
    const char *w;

    ++pl_human->movesToSolve;

    w = pick_word_human_helper(0, "Your turn: ");
    cmp = matches(pl_ai->word, w);
    printf("\t\t... %d match(es).\n", cmp);

    if (cmp == W_LEN && !has_repeats(pl_human->word)) {
        pl_human->solved = 1;
    }
}

int another_round()
{
    char c, input;
    while (1)
    {
        printf("\nAnother round [y/n]? ");
        input = scanf("%c", &c);
        fflush(stdin);

        if (input != 1)
            continue;

        if (tolower(c) == 'y')
            return 1;
        else if (tolower(c) == 'n')
            return 0;
    }
}

const char *pick_word_human_helper(int pick, const char *prompt)
{
    int i, c;
    const char *w;
    char s[W_LEN];

    while (1)
    {
        printf(prompt);
        for (i = 0; (c = getchar()) != '\n'; ++i)
            if (i < W_LEN)
                s[i] = to_lower_rus_866(c);

        fflush(stdin);

        if (i != W_LEN) {
            printf("%d letters expected.\n", W_LEN);
            continue;
        } else if ((w = dict_match(s)) == UNKNOWN_WRD) {
            puts("Unknown word.");
            continue;
        } else if (pick && has_repeats(s)) {
            puts("Repeated letters.");
            continue;
        }

        return w;
    }
}
