#include "malloc.h"

static m_header_t *head;

/**
 * find_free_block - Finds a free block of sufficient size.
 *
 * @size: The size needed.
 *
 * Return: Pointer to a suitable block or NULL.
 */
static m_header_t *find_free_block(size_t size)
{
	m_header_t *curr = head;

	while (curr)
	{
		if (curr->free && curr->size >= size)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

/**
 * _malloc - Allocates memory of a given size.
 *
 * @size: The size of memory to allocate.
 *
 * Return: A pointer to the allocated memory, or NULL on failure.
 */
void *_malloc(size_t size)
{
	m_header_t *block;
	void *mem;
	size_t total_size;

	if (size == 0)
		return (NULL);

	size = ALIGN4(size);
	block = find_free_block(size);

	if (block)
	{
		block->free = 0;
		return ((void *)(block + 1));
	}

	total_size = sizeof(m_header_t) + size;
	mem = sbrk(total_size);
	if (mem == (void *)-1)
		return (NULL);

	block = (m_header_t *)mem;
	block->size = size;
	block->free = 0;
	block->next = head;
	head = block;

	return ((void *)(block + 1));
}
