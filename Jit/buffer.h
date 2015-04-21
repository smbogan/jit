
#ifndef __JIT_BUFFER_H__
#define __JIT_BUFFER_H__

#include "errors.h"

typedef struct 
{
	int count;
	int size;
	int growby;
	char data[1];
} buffer;

buffer * buffer_new(int start_size, int growby);
error buffer_write(buffer ** b, char c);
int buffer_count(buffer * b);
char buffer_get(buffer * b, int index);
void buffer_free(buffer * b);

#endif