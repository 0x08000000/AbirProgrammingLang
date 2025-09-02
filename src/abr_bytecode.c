#include "abr_bytecode.h"

void abr_bytecode_init_block(struct abr_bytecode_block *blk)
{
    if (blk == NULL) {
        LOG("blk is null!\n\r");
        return;
    }
    blk->count = 0;
    blk->capacity = 0;
    blk->code = NULL;
}

void abr_bytecode_write_opcode(struct abr_bytecode_block *blk, op_code code)
{
    int old_capacity;

    BUG_ON(blk == NULL, "blk cannot be null!");

    if (blk->count + 1 > blk->capacity) {
        old_capacity = blk->capacity;
        blk->capacity = abr_mem_grow_capacity(old_capacity);
        blk->code = abr_mem_grow_array(uint8_t, blk->code, 
            old_capacity, blk->capacity);
    }
    blk->code[blk->count] = code;
    blk->count++;
}

void abr_bytecode_free_block(struct abr_bytecode_block *blk)
{
    if (blk == abr_nullptr)
        return;
    
    abr_mem_free_array(blk);
    abr_bytecode_init_block(blk);
}