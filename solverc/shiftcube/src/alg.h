#ifndef ALG_H
#define ALG_H

#include "main.h"
#include "move.h"

typedef struct {
    move_e *moves;
    size_t length;
    size_t size;
} alg_s;

typedef struct {
    alg_s *list;
    size_t num_algs;
    size_t size;
} alg_list_s;

// no particular reason for this choice, 4 is just a nice and small power of two
#define MIN_LIST_RESIZE 4

alg_s* alg_create(size_t size);
alg_s* alg_copy(const alg_s *src);
alg_s  alg_static_copy(const alg_s *src);
void   alg_free(alg_s *alg);

bool alg_insert(alg_s *moves, move_e move, size_t index);
bool alg_delete(alg_s *moves, size_t index);
size_t alg_lookup(const alg_s *alg, move_e move);
alg_s* alg_from_alg_str(const char *alg_str);

void alg_invert(alg_s *alg);
void alg_simplify(alg_s *alg);
void alg_rotate_on_y(alg_s *alg, uint8_t y_turns);

move_e* alg_concat(alg_s *dest, const alg_s *src);
#endif // ALG_H
