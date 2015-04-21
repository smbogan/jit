#ifndef __JIT_MEMORY_H__
#define __JIT_MEMORY_H__

#include<stdlib.h>

#define ALLOC(x) malloc(x)
#define DEALLOC(x) free(x)

#ifndef NULL
#define NULL ((void *)0)
#endif

#endif