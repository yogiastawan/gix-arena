#include <gix_arena/core/gix_arena_impl.h>
#include <gix_arena/utils/gix_arena_define.h>
#include <stdlib.h>

struct _GixArena {
    usize size;
    usize used;
    u8* memory;
};

GixArena* gix_arena_new(usize size) {
    GixArena* arena = malloc(sizeof(GixArena));

    if (!arena) {
        return NULL;
    }

    arena->size = size;
    arena->used = 0;
    arena->memory = malloc(size);
    if (!arena->memory) {
        return NULL;
    }

    return arena;
}

// b8 gix_arena_add_size(GixArena* arena, usize size) {
//     u8* new_memory = realloc(arena->memory, arena->size + size);
//     if (!new_memory) {
//         return 0;  // false
//     }

//     arena->memory = new_memory;
//     arena->size += size;
//     return 1;  // true
// }

void* gix_arena_alloc(GixArena* arena, usize size) {
    if (arena->used + size > arena->size) {
        return NULL;
    }

    void* ptr = arena->memory + arena->used;
    arena->used += size;
    return ptr;
}

void gix_arena_destroy(GixArena* arena) {
    if (arena) {
        free(arena->memory);
        free(arena);
    }
}