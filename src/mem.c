#include <stdlib.h>
#include <stddef.h>
#include "assert.h"
#include "except.h"
#include "mem.h"

// data
const except_t MemFailed = {"Allocation Failed"};

// functions
void *mem_alloc(long nbytes, const char *file, int line) {
	void *ptr;
	assert(nbytes > 0);
	ptr = malloc(nbytes);
	if (ptr == NULL) {
		if (file == NULL)
			RAISE(MemFailed);
		else
			except_raise(&MemFailed, file, line);
	}
	return ptr;
}

void *mem_calloc(long count, long nbytes, const char *file, int line)
{
	void *ptr;
	assert(count > 0);
	assert(nbytes > 0);
	ptr = calloc(count, nbytes);
	if (ptr == NULL) {
		if (file == NULL)
			RAISE(MemFailed);
		else
			except_raise(&MemFailed, file, line);
	}
	return ptr;
}

void *mem_resize(void *ptr, long nbytes, const char *file, int line)
{
	assert(ptr);
	assert(nbytes > 0);
	ptr = realloc(ptr, nbytes);
	if (ptr == NULL) {
		if (file == NULL)
			RAISE(MemFailed);
		else
			except_raise(&MemFailed, file, line);
	}
	return ptr;
}

void mem_free(void *ptr, const char *file, int line)
{
	if (ptr) free(ptr);
}
