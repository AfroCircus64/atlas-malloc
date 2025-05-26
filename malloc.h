#ifndef MALLOC_H
#define MALLOC_H
#include <stdio.h>

/* STRUCTURES */

/**
 * struct m_header_s - Structure representing a block of memory in the heap.
 * @size: The size of the block.
 * @free: A flag indicating whether the block is free (1) or allocated (0).
 * @next: Pointer to the next block in the linked list.
 */
typedef struct m_header_s
{
	size_t size;
	int free;
	struct m_header_s *next;
} m_header_t;



/* FUNCTION PROTOTYPES */
void *naive_malloc(size_t size);
void *_malloc(size_t size);
void _free(void *ptr);


#endif /* MALLOC_H */
