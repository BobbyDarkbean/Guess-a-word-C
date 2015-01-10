#ifndef DICT_H_INCLUDED
#define DICT_H_INCLUDED

#include <stdlib.h>

#define W_LEN 4
#define UNKNOWN_WRD ((const char *)0)

int load_dict();
void unload_dict();
const char *w_dict();

#define DICT (w_dict())

size_t w_dict_size();
size_t pick_dict_size();

const char *dict_match(const char *w);

#endif // DICT_H_INCLUDED
