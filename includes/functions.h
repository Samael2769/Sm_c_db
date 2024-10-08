
#pragma once

#include "structs.h"

void print_prompt();
void read_input(InputBuffer* input_buffer);
InputBuffer* new_input_buffer();
void close_input_buffer(InputBuffer* input_buffer);
ExecuteResult execute_statement(Statement* statement, Table* table);
PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);
MetaCommandResult do_meta_command(InputBuffer* input_buffer, Table* table);

Table* db_open(const char* filename);