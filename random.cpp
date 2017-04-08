#include < cstdlib>
#include "random.h"
unsigned int randomInteger :: operator ( ) (unsigned int max)
{
	unsigned int rval = rand();
	return rval % max;
}