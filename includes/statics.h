#ifndef INCLUDES_STATICS_H
#define INCLUDES_STATICS_H

#include <structs.h>

#define ID_SIZE (size_of_attribute(Row, id))
#define USERNAME_SIZE (size_of_attribute(Row, username))
#define EMAIL_SIZE (size_of_attribute(Row, email))
#define ID_OFFSET (0)
#define USERNAME_OFFSET (ID_OFFSET + ID_SIZE)
#define EMAIL_OFFSET (USERNAME_OFFSET + USERNAME_SIZE)
#define ROW_SIZE (ID_SIZE + USERNAME_SIZE + EMAIL_SIZE)

#define PAGE_SIZE (4096)

#define NODE_TYPE_SIZE (sizeof(uint8_t))
#define NODE_TYPE_OFFSET (0)
#define IS_ROOT_SIZE (sizeof(uint8_t))
#define IS_ROOT_OFFSET (NODE_TYPE_SIZE)
#define PARENT_POINTER_SIZE (sizeof(uint32_t))
#define PARENT_POINTER_OFFSET (IS_ROOT_OFFSET + IS_ROOT_SIZE)
#define COMMON_NODE_HEADER_SIZE (NODE_TYPE_SIZE + IS_ROOT_SIZE + PARENT_POINTER_SIZE)

#define LEAF_NODE_NUM_CELLS_SIZE (sizeof(uint32_t))
#define LEAF_NODE_NUM_CELLS_OFFSET (COMMON_NODE_HEADER_SIZE)
#define LEAF_NODE_NEXT_LEAF_SIZE (sizeof(uint32_t))
#define LEAF_NODE_NEXT_LEAF_OFFSET (LEAF_NODE_NUM_CELLS_OFFSET + LEAF_NODE_NUM_CELLS_SIZE)
#define LEAF_NODE_HEADER_SIZE (COMMON_NODE_HEADER_SIZE + LEAF_NODE_NUM_CELLS_SIZE + LEAF_NODE_NEXT_LEAF_SIZE)

#define LEAF_NODE_KEY_SIZE (sizeof(uint32_t))
#define LEAF_NODE_KEY_OFFSET (0)
#define LEAF_NODE_VALUE_SIZE (ROW_SIZE)
#define LEAF_NODE_VALUE_OFFSET (LEAF_NODE_KEY_OFFSET + LEAF_NODE_KEY_SIZE)
#define LEAF_NODE_CELL_SIZE (LEAF_NODE_KEY_SIZE + LEAF_NODE_VALUE_SIZE)
#define LEAF_NODE_SPACE_FOR_CELLS (PAGE_SIZE - LEAF_NODE_HEADER_SIZE)
#define LEAF_NODE_MAX_CELLS (LEAF_NODE_SPACE_FOR_CELLS / LEAF_NODE_CELL_SIZE)

#define LEAF_NODE_LEFT_SPLIT_COUNT ((LEAF_NODE_MAX_CELLS + 1) / 2)
#define LEAF_NODE_RIGHT_SPLIT_COUNT (LEAF_NODE_MAX_CELLS + 1 - LEAF_NODE_LEFT_SPLIT_COUNT)

#define INTERNAL_NODE_NUM_KEYS_SIZE (sizeof(uint32_t))
#define INTERNAL_NODE_NUM_KEYS_OFFSET (COMMON_NODE_HEADER_SIZE)
#define INTERNAL_NODE_RIGHT_CHILD_SIZE (sizeof(uint32_t))
#define INTERNAL_NODE_RIGHT_CHILD_OFFSET (INTERNAL_NODE_NUM_KEYS_OFFSET + INTERNAL_NODE_NUM_KEYS_SIZE)
#define INTERNAL_NODE_HEADER_SIZE (COMMON_NODE_HEADER_SIZE + INTERNAL_NODE_NUM_KEYS_SIZE + INTERNAL_NODE_RIGHT_CHILD_SIZE)
#define INTERNAL_NODE_MAX_CELLS (3)

#define INTERNAL_NODE_KEY_SIZE (sizeof(uint32_t))
#define INTERNAL_NODE_CHILD_SIZE (sizeof(uint32_t))
#define INTERNAL_NODE_CELL_SIZE (INTERNAL_NODE_CHILD_SIZE + INTERNAL_NODE_KEY_SIZE)

#endif
