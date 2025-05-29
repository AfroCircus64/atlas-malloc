#ifndef MALLOC_H
#define MALLOC_H
#include <stdio.h>
#include <unistd.h>

#define ALIGN4(x) (((x) + 3) & ~0x3)

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

/**
 * struct nm_header_s - Structure representing a block of memory in the heap
 * for the naive malloc implementation.
 *
 * @size: The size of the block.
 */
typedef struct nm_header_s
{
	size_t size;
} nm_header_t;


/* FUNCTION PROTOTYPES */
void *naive_malloc(size_t size);
void *_malloc(size_t size);
void _free(void *ptr);


#endif /* MALLOC_H */
