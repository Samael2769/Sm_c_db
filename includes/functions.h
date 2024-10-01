
#pragma once

#include "structs.h"

void print_prompt();
void read_input(InputBuffer* input_buffer);
InputBuffer* new_input_buffer();
void close_input_buffer(InputBuffer* input_buffer);
void execute_statement(Statement* statement);
PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);
MetaCommandResult do_meta_command(InputBuffer* input_buffer);