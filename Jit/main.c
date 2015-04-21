#include "buffer.h"


int main()
{
	buffer * b = buffer_new(5, 5);
	char v;

	buffer_write(&b, 'a');
	buffer_write(&b, 'b');
	buffer_write(&b, 'c');
	buffer_write(&b, 'd');
	buffer_write(&b, 'e');
	buffer_write(&b, 'f');

	v = buffer_get(b, 2);

	buffer_free(b);

	return 0;
}