#include <stdlib.h>
#include "dict.h"

#include "word.h"

int has_repeats(const char *w)
{
    const char *i, *j, *i_end, *j_end;
    j_end = w + W_LEN;
    i_end = j_end - 1;

    for (i = w; i != i_end; ++i) {
        for (j = i + 1; j != j_end; ++j) {
            if (*i == *j)
                return 1;
        }
    }

    return 0;
}

int matches(const char *ptrn, const char *cmpr)
{
    int m;
    const char *i, *j, *i_end, *j_end;
    i_end = ptrn + W_LEN;
    j_end = cmpr + W_LEN;

    m = 0;
    for (i = ptrn; i != i_end; ++i) {
        for (j = cmpr; j != j_end; ++j) {
            if (*i == *j)
                ++m;
        }
    }

    return m;
}

char to_lower_rus_866(char c)
{
    if (c == -16)
        return -15;
    else if (-128 <= c && c < -112)
        return c + 32;
    else if (-112 <= c && c < -96)
        return c + 80;
    else
        return c;
}
