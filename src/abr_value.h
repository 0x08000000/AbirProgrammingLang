#ifndef __ABR_VALUE_H
#define __ABR_VALUE_H

#include "abr_memory.h"

typedef double abr_value;
struct abr_constant_pool
{
    int capacity;
    int count;
    abr_value *values_list;
};

void abr_val_init_constant_pool(struct abr_constant_pool* pool);
void abr_val_write_constant(struct abr_constant_pool* pool, abr_value value);
void abr_val_free_constant_pool(struct abr_constant_pool* pool);

#endif
