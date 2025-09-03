#ifndef __ABR_MEMORY_H
#define __ABR_MEMORY_H

#include "abr_common.h"

static inline int _abr_grow_capacity(int old)
{
    return old < 8 ? 8 : old * 2;
}
#define abr_mem_grow_capacity(old_c) \
    _abr_grow_capacity((old_c))

static inline void *_abr_resize_array(void *ptr, size_t old_size, 
    size_t new_size)
{
    
    if (new_size == 0) {
        if (ptr == abr_nullptr) {
            LOG("(fatal) trying to free a null pointer!\n")
            free(ptr);
        }
        return abr_nullptr;
    }

    void *res = realloc(ptr, new_size);
    BUG_ON(res == abr_nullptr, "realloc on block failed!");

    return res;
}
#define abr_mem_grow_array(type, ptr, old_count, new_count) \
        _abr_resize_array((ptr),   \
            (old_count) * sizeof(type),  \
            (new_count) * sizeof(type)) \

#define abr_mem_free_array(ptr) \
        _abr_resize_array((ptr), 0, 0); \

#endif