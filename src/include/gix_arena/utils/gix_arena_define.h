#ifndef __GIX_ARENA_DEFINE_H__
#define __GIX_ARENA_DEFINE_H__

#include <gix_arena/utils/gix_arena_platform.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef GIX_DEFINE_TYPES
#define GIX_DEFINE_TYPES
typedef int8_t i8;
typedef uint8_t u8;
typedef int16_t i16;
typedef uint16_t u16;
typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;

typedef float f32;
typedef double f64;

typedef uint8_t b8;
typedef uint32_t b32;

typedef size_t usize;
#endif

#ifndef GAAPI

#ifdef GIX_ARENA_PLATFORM_WINDOWS
#define GAAPI __declspec(dllexport)
#else
#define GAAPI
#endif

#endif

#ifdef __cplusplus
}
#endif

#endif /* __GIX_ARENA_DEFINE_H__ */