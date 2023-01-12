#ifndef INF
#define INF
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

int _putchar(char c);

struct num {
	int *num;
	ssize_t len;
	int over;
};

typedef struct num res;

#endif	
