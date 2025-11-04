#include <gix_arena/gix_arena.h>
#include <stdio.h>
#include <string.h>

typedef struct _MyData {
    int a;
    float b;
} MyData;

typedef struct _Person {
    char name[50];
    int age;
} Person;

int main(int argc, char const* argv[]) {
    printf("EXample Gix Arena\n");

    printf("Gix Arena Version: %s (%d)\n", gix_arena_version(),
           gix_arena_version_num());

    GixArena* arena = gix_arena_new(1024);
    if (!arena) {
        printf("Failed to create arena\n");
        return 1;
    }

    // allocate 10 MyData structs
    MyData* data = gix_arena_alloc(arena, sizeof(MyData) * 10);
    if (!data) {
        printf("Failed to allocate data\n");
        gix_arena_destroy(arena);
        return 1;
    }

    for (u8 i = 0; i < 10; i++) {
        data[i].a = i;
        data[i].b = i * 1.5f;
    }

    // allocate 15 Person structs
    Person* people = gix_arena_alloc(arena, sizeof(Person) * 15);
    if (!people) {
        printf("Failed to allocate people\n");
        gix_arena_destroy(arena);
        return 1;
    }

    for (u8 i = 0; i < 15; i++) {
        people[i].age = 20 + i;
        memcpy(people[i].name, "Yogi Astawan", 13);
    }

    for (u8 i = 0; i < 10; i++) {
        printf("MyData[%d]: a=%d, b=%f\n", i, data[i].a, data[i].b);
    }

    for (u8 i = 0; i < 15; i++) {
        printf("Person[%d]: name=%s, age=%d\n", i, people[i].name,
               people[i].age);
    }

    gix_arena_destroy(arena);

    return 0;
}
