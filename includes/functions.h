
#pragma once

#include "structs.h"

void print_prompt();
void read_input(InputBuffer* input_buffer);
InputBuffer* new_input_buffer();
void close_input_buffer(InputBuffer* input_buffer);
ExecuteResult execute_statement(Statement* statement, Table* table);
PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);
MetaCommandResult do_meta_command(InputBuffer* input_buffer, Table* table);

Pager *pager_open(const char* filename);
void pager_flush(Pager* pager, uint32_t page_num);
void db_close(Table* table);

void* get_page(Pager* pager, uint32_t page_num);

Table* db_open(const char* filename);

Cursor* table_start(Table* table);
Cursor* table_find(Table* table, uint32_t key);
void * cursor_value(Cursor *cursor);
void cursor_advance(Cursor* cursor);

void deserialize_row(void* source, Row* destination);
void serialize_row(Row* source, void* destination);


void initialize_leaf_node(void* node);
void initialize_internal_node(void* node);
uint32_t * leaf_node_num_cells(void* node);
void* leaf_node_cell(void* node, uint32_t cell_num);
uint32_t* leaf_node_key(void* node, uint32_t cell_num);
void* leaf_node_value(void* node, uint32_t cell_num);
void leaf_node_insert(Cursor* cursor, uint32_t key, Row* value);
Cursor * leaf_node_find(Table* table, uint32_t page_num, uint32_t key);

NodeType get_node_type(void* node);
void set_node_type(void* node, NodeType type);

void print_constants();
void print_tree(Pager* pager, uint32_t page_num, uint32_t indentation_level);

uint32_t get_unused_page_num(Pager* pager);
void leaf_node_split_and_insert(Cursor* cursor, uint32_t key, Row* value);
void create_new_root(Table* table, uint32_t right_child_page_num);
uint32_t * internal_node_num_keys(void* node);
uint32_t * internal_node_right_child(void* node);
uint32_t * internal_node_cell(void* node, uint32_t cell_num);
uint32_t * internal_node_child(void* node, uint32_t child_num);
uint32_t * internal_node_key(void* node, uint32_t key_num);
Cursor * internal_node_find(Table *table, uint32_t page_num, uint32_t key);
uint32_t get_node_max_key(Pager* pager, void* node);
bool is_node_root(void* node);
void set_node_root(void* node, bool is_root);
uint32_t * leaf_node_next_leaf(void* node);
uint32_t * node_parent(void* node);
void update_internal_node_key(void* node, uint32_t old_key, uint32_t new_key) ;
uint32_t internal_node_find_child(void* node, uint32_t key);
void internal_node_insert(Table* table, uint32_t parent_page_num, uint32_t child_page_num);
void internal_node_split_and_insert(Table* table, uint32_t parent_page_num, uint32_t child_page_num);

void print_row(Row* row);
