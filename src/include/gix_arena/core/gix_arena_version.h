#ifndef __GIX_ARENA_VERSION_H__
#define __GIX_ARENA_VERSION_H__

#include <gix_arena/utils/gix_arena_define.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef GIX_ARENA_MAJOR_VERSION
#define GIX_ARENA_MAJOR_VERSION \
    Error:                      \
    Major version not defined
#endif
#ifndef GIX_ARENA_MINOR_VERSION
#define GIX_ARENA_MINOR_VERSION \
    Error:                      \
    Minor version not defined
#endif

#ifndef GIX_ARENA_PATCH_VERSION
#define GIX_ARENA_PATCH_VERSION \
    Error:                      \
    Patch version not defined
#endif

#ifndef GIX_ARENA_VERSION
#define GIX_ARENA_VERSION \
    Error:                \
    Version not defined
#endif

#define GIX_ARENA_VERSION_NUM                                           \
    ((GIX_ARENA_MAJOR_VERSION << 16) | (GIX_ARENA_MINOR_VERSION << 8) | \
     GIX_ARENA_PATCH_VERSION)

/**
 * @brief Get version of Gix Arena in string.
 *
 * @return String literal of the Gix Arena version.
 */
GAAPI const char* gix_arena_version(void);

/**
 * @brief Get version of Gix Arena in number.
 *
 * @return Number of the Gix Arena version.
 */
GAAPI int gix_arena_version_num(void);

#ifdef __cplusplus
}
#endif

#endif /* __GIX_ARENA_VERSION_H__ */
