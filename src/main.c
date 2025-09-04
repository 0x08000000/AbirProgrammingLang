#include "abr_bytecode.h"
#include "abir_debug.h"
#include "abr_value.h"

int main(int argc, char *argv[])
{
    struct abr_bytecode_block blk;
    abr_bytecode_init_block(&blk);
    abr_val_init_constant_pool(&blk.constants);
    int constant_idx = abr_bytecode_add_constant(&blk, 1.2);
    abr_bytecode_write_opcode(&blk, OP_CONSTANT);
    abr_bytecode_write_opcode(&blk, constant_idx);
    abr_bytecode_write_opcode(&blk, OP_RETURN);
    abr_dbg_dissasemble_block(&blk, "test");
    abr_bytecode_free_block(&blk);
    return 0;
}
