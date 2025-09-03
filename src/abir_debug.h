#ifndef __ABR_DEBUG_H
#define __ABR_DEBUG_H

#include "abr_common.h"
#include "abr_bytecode.h"

void abr_dbg_dissasemble_block(struct abr_bytecode_block *blk, const char *name);
int abr_dbg_dissasemble_instruction(struct abr_bytecode_block *blk, int offset);

#endif
