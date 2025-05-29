#include "malloc.h"

/**
 * _free - Frees the memory allocated by _malloc.
 *
 * @ptr: Pointer to the memory to free.
 *
 * Return: None.
 */
void _free(void *ptr)
{
	m_header_t *header;

	if (!ptr)
	{
		return;
	}

	header = (m_header_t *)ptr - 1;
	header->free = 1;
}
