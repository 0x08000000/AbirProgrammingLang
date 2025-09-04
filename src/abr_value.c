#include "abr_value.h"

void abr_val_init_constant_pool(struct abr_constant_pool* pool)
{
    BUG_ON(array == abr_nullptr, "constant pool is null!\n\r");

    pool->count = 0;
    pool->capacity = 0;
    pool->values_list = abr_nullptr;
}

void abr_val_write_constant(struct abr_constant_pool* pool, abr_value value)
{
    int old_capacity;
    
    BUG_ON(pool == abr_nullptr, "constants pool is null!");

    if (pool->count + 1 > pool->capacity) {
        old_capacity = pool->capacity;
        pool->capacity = abr_mem_grow_capacity(old_capacity);
        pool->values_list = abr_mem_grow_array(abr_value, pool->values_list, 
            old_capacity, pool->capacity);
    }
    pool->values_list[pool->count] = value;
    pool->count++;
}

void abr_val_free_constant_pool(struct abr_constant_pool* pool)
{
    if (pool == abr_nullptr)
        return;
    
    abr_mem_free_array(pool);
    abr_val_init_constant_pool(pool);
}