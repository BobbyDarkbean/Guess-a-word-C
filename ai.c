#include <stdlib.h>
#include <string.h>
#include "word.h"
#include "dict.h"

#include "ai.h"

static const char **sample_words;
static int words_left;

int is_word_valid(const char *ptrn, const char *cmpr, int mt);

const char *pick_word_ai()
{
    return sample_words[rand() % pick_dict_size()];
}

void turn_ai(player_info *pl_ai, player_info *pl_human)
{
    int cmp;
    const char *w;
    char buff[W_LEN + 1];

    ++pl_ai->movesToSolve;

    w = sample_words[rand() % words_left];
    cmp = matches(pl_human->word, w);

    strncpy(buff, w, W_LEN);
    buff[W_LEN] = '\0';
    printf("Computer: %s\n\t\t... %d match(es). ", buff, cmp);

    if (cmp == W_LEN) {
        pl_ai->solved = 1;
    } else {
        filter(w, cmp);
        printf("%d words left.", words_left);
    }
    putchar('\n');
}

void filter(const char *ptrn, int mt)
{
    const char **i, **j, **end;
    i = j = sample_words;
    end = sample_words + words_left;

    while (j != end) {
        if (is_word_valid(ptrn, *j, mt) && *j != ptrn) {
            *i++ = *j++;
        } else {
            ++j;
            --words_left;
        }
    }
}

void allocate_sample_words_mem(size_t n)
{ sample_words = (const char **)malloc(sizeof(char *) * n); }

void free_sample_words_mem()
{ free(sample_words); }

void initialize_sample_words()
{
    const char *pw, *end, **ppw;

    pw = DICT;
    end = pw + W_LEN * w_dict_size();
    ppw = sample_words;

    while (pw != end) {
        if (!has_repeats(pw))
            *ppw++ = pw;
        pw += W_LEN;
    }

    words_left = ppw - sample_words;
}

int is_word_valid(const char *ptrn, const char *cmpr, int mt)
{
    return mt ? matches(ptrn, cmpr) == mt : !matches(ptrn, cmpr);
}
