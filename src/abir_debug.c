#include "abir_debug.h"

static int basic_instruction(struct abr_bytecode_block *blk, 
    int opcode, int offset);

#define DEF_OPCODE_INFO(n_opcode, n_jmp, fn_dbg_ptr) \
        {.opcode = (n_opcode), .opcode_str = #n_opcode, .n_jump=(n_jmp),    \
         .fn_dbg = &(fn_dbg_ptr)} 
struct 
{
    int opcode;
    char *opcode_str;
    int n_jump;
    int (*fn_dbg)(struct abr_bytecode_block *blk, int opcode, int offset);
} _opcode_dbg_info[] = 
{
    [OP_RETURN] = DEF_OPCODE_INFO(OP_RETURN, 1, basic_instruction),
};

static int basic_instruction(struct abr_bytecode_block *blk, 
    int opcode, int offset)
{
    _UNUSED(blk);

    printf("%s\n\r", _opcode_dbg_info[opcode].opcode_str);
    return offset +  _opcode_dbg_info[opcode].n_jump;
}

void abr_dbg_dissasemble_block(struct abr_bytecode_block *blk, const char *name)
{
    if (blk == abr_nullptr) {
        printf("bytecode block is null, nothing to disassemble!\n\r");
        return;
    }

    printf("disassembling %s!\n\r", name ? name : "(empty)");

    int offset = 0;
    while(offset < blk->count) {
        offset = abr_dbg_dissasemble_instruction(blk, offset);
    }
}

int abr_dbg_dissasemble_instruction(struct abr_bytecode_block *blk, int offset)
{
    BUG_ON(blk == abr_nullptr, "block is null, but should be already checked!\n");
    BUG_ON(offset > blk->count, "offset is greater than count of instructions!\n");

    printf("%04d\t", offset);

    uint8_t instr = blk->code[offset];
    return offset + _opcode_dbg_info[instr].fn_dbg(blk, 
                                          instr, 
                                          offset);
}