#ifndef __GIX_ARENA_IMPL_H__
#define __GIX_ARENA_IMPL_H__

#include <gix_arena/utils/gix_arena_define.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _GixArena GixArena;

GAAPI GixArena* gix_arena_new(usize size);

// GAAPI b8 gix_arena_add_size(GixArena* arena, usize size);

GAAPI void* gix_arena_alloc(GixArena* arena, usize size);

GAAPI void gix_arena_destroy(GixArena* arena);

#ifdef __cplusplus
}
#endif

#endif /* __GIX_ARENA_IMPL_H__ */