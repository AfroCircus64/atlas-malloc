#include "malloc.h"

/**
 * naive_malloc - Allocates memory of a given size.
 *
 * @size: The size of memory to allocate.
 *
 * Return: A pointer to the allocated memory, or NULL on failure.
 */
void *naive_malloc(size_t size)
{
	size_t total_size;
	nm_header_t *header;
	void *mem;

	if (size == 0)
		return (NULL);

	total_size = sizeof(nm_header_t) + size;

	mem = sbrk(total_size);
	if (mem == (void *)-1)
		return (NULL);

	header = (nm_header_t *)mem;
	header->size = size;

	return ((void *)(header + 1));
}
