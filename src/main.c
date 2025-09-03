#include "abr_bytecode.h"
#include "abir_debug.h"

int main(int argc, char *argv[])
{
    struct abr_bytecode_block blk;
    abr_bytecode_init_block(&blk);
    abr_bytecode_write_opcode(&blk, OP_RETURN);
    abr_dbg_dissasemble_block(&blk, "test");
    abr_bytecode_free_block(&blk);
    return 0;
}
