
#include "buffer.h"
#include "memory.h"

buffer * buffer_new(int start_size, int growby)
{
	buffer * b = (buffer *)ALLOC(sizeof(buffer) - 1 + growby);

	if (!b)
		return NULL;

	b->count = 0;
	b->size = growby;
	b->growby = growby;

	return b;
}

error buffer_grow(buffer ** b)
{
	int i = 0;

	buffer * n = (buffer *)ALLOC(sizeof(buffer) - 1 + (*b)->size + (*b)->growby);
	
	if (!n)
		return memory_error;
	
	n->count = (*b)->count;
	n->size = (*b)->size + (*b)->growby;
	n->growby = (*b)->growby;

	for (; i < (*b)->count; i++)
	{
		n->data[i] = (*b)->data[i];
	}

	DEALLOC(*b);

	*b = n;

	return noerror;
}

error buffer_write(buffer ** b, char c)
{
	if ((*b)->count == (*b)->size)
	{
		if (buffer_grow(b) != noerror)
		{
			return memory_error;
		}
	}

	(*b)->data[(*b)->count] = c;
	(*b)->count++;

	return noerror;
}

int buffer_count(buffer * b)
{
	return b->count;
}

char buffer_get(buffer * b, int index)
{
	return b->data[index];
}

void buffer_free(buffer * b)
{
	DEALLOC(b);

}