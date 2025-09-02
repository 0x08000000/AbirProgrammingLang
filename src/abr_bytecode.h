#ifndef __ABR_BYTECODE_H
#define __ABR_BYTECODE_H

#include "abr_common.h"
#include "abr_memory.h"

typedef enum
{
    OP_RETURN,
}op_code;

struct abr_bytecode_block
{
    int count;
    int capacity;
    uint8_t *code;
};

void abr_bytecode_init_block(struct abr_bytecode_block *blk);
void abr_bytecode_write_opcode(struct abr_bytecode_block *blk, op_code code);
void abr_bytecode_free_block(struct abr_bytecode_block *blk);

#endif