
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

Cursor* table_start(Table* table);
Cursor* table_find(Table* table, uint32_t key);
void * cursor_value(Cursor *cursor);
void cursor_advance(Cursor* cursor);


void initialize_leaf_node(void* node);
uint32_t * leaf_node_num_cells(void* node);
void* leaf_node_cell(void* node, uint32_t cell_num);
uint32_t* leaf_node_key(void* node, uint32_t cell_num);
void* leaf_node_value(void* node, uint32_t cell_num);
void leaf_node_insert(Cursor* cursor, uint32_t key, Row* value);
Cursor * leaf_node_find(Table* table, uint32_t page_num, uint32_t key);

NodeType get_node_type(void* node);
void set_node_type(void* node, NodeType type);

void print_constants();
void print_lead_node(void *node);