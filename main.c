#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

#define APP_NAME ("Guess a word")
#define APP_VER 1.02
#define YEAR (__DATE__ + 7)

int main()
{
    if (!load_dict())
        return 1;

    system("chcp 866 > NUL");

    printf("%s %lg %s\n\n", APP_NAME, APP_VER, YEAR);

    srand((unsigned)time(NULL));
    rand();
    rand();

    play_game();

    unload_dict();
    return 0;
}
