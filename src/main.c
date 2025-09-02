#include "abr_bytecode.h"

int main(int argc, char *argv[])
{
    struct abr_bytecode_block blk;
    abr_bytecode_init_block(&blk);
    abr_bytecode_write_opcode(&blk, OP_RETURN);
    abr_bytecode_free_block(&blk);
    return 0;
}
