#ifndef __GIX_ARENA_IMPL_H__
#define __GIX_ARENA_IMPL_H__

#include <gix_arena/utils/gix_arena_define.h>

#ifdef __cplusplus
extern "C" {
#endif

/// @brief Opaque structure for GixArena
typedef struct _GixArena GixArena;

/**
 * @brief Create a new GixArena with the specified size.
 *
 * @param size The size of arena in bytes.
 *
 * @return A Pointer to the newly created GixArena, or NULL if failed.
 */
GAAPI GixArena* gix_arena_new(usize size);

// GAAPI b8 gix_arena_add_size(GixArena* arena, usize size);

/**
 * @brief Allocate memory to the arena.
 *
 * @param arena The GixArena to allocate memory from.
 * @param size The size of memory to allocate in bytes.
 *
 * @return A pointer to the allocated memory, or NULL if allocation failed.
 */
GAAPI void* gix_arena_alloc(GixArena* arena, usize size);

/**
 * @brief Destroy the GixArena and free it's memory.
 *
 * @param arena The GixArena to destroy.
 */
GAAPI void gix_arena_destroy(GixArena* arena);

#ifdef __cplusplus
}
#endif

#endif /* __GIX_ARENA_IMPL_H__ */