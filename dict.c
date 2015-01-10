#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "word.h"

#include "dict.h"

char *_words;

int load_dict()
{
    const int DEFAULT_ALLOC = 0x100 * W_LEN;

    FILE *f;
    int c, sz;
    char *i, *last, *tmp;

    if (!(f = fopen("words", "r"))) {
        puts("Can not open file.");
        return 0;
    }

    i = _words;
    last = i;
    sz = 0;
    while ((c = fgetc(f)) != EOF) {
        if (i == last) {
            if (!(tmp = (char *)realloc(_words, sizeof(char) * (sz + DEFAULT_ALLOC) + 1))) {
                puts("Not enough memory.");
                return 0;
            }

            _words = tmp;
            i = _words + sz;
            last = i + DEFAULT_ALLOC;
            sz += DEFAULT_ALLOC;
        }

        *i++ = c;
    }
    *i = '\0';

    if (!(tmp = (char *)realloc(_words, sizeof(char) * w_dict_size() * W_LEN + 1))) {
        puts("Not enough memory.");
        return 0;
    }
    _words = tmp;

    return 1;
}

void unload_dict()
{ free(_words); }

const char *w_dict()
{ return _words; }

size_t w_dict_size()
{ return strlen(_words) / W_LEN; }

size_t pick_dict_size()
{
    int sz;
    const char *pw;

    sz = 0;
    pw = DICT;

    while (*pw) {
        if (!has_repeats(pw))
            ++sz;
        pw += W_LEN;
    }

    return sz;
}

const char *dict_match(const char *w)
{
    const char *i, *j, *i_end, *j_end;
    i = DICT;
    i_end = i + W_LEN * w_dict_size();
    j_end = w + W_LEN;

    while (i != i_end) {
        j = w;
        while (j != j_end) {
            if (*i == *j) {
                ++i;
                ++j;
            } else {
                i += j_end - j;
                break;
            }
        }

        if (j == j_end)
            return i - W_LEN;
    }

    return UNKNOWN_WRD;
}
