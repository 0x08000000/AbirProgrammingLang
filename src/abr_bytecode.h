#ifndef __ABR_BYTECODE_H
#define __ABR_BYTECODE_H

#include "abr_common.h"
#include "abr_memory.h"
#include "abr_value.h"

typedef enum
{
    OP_CONSTANT, /* OP_CONSTANT <index in constant pool> */
    OP_RETURN,
}op_code;

struct abr_bytecode_block
{
    int count;
    int capacity;
    uint8_t *code;
    struct abr_constant_pool constants;
};

void abr_bytecode_init_block(struct abr_bytecode_block *blk);
void abr_bytecode_write_opcode(struct abr_bytecode_block *blk, op_code code);
int abr_bytecode_add_constant(struct abr_bytecode_block *blk, abr_value val);
void abr_bytecode_free_block(struct abr_bytecode_block *blk);

#endif