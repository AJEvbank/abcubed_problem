#ifndef MAIN_H

#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "getopt.h"

struct result {
	int sum, x, y;
	struct result * next;
};

struct solution {
	int sum, a, b, c, d;
};


#endif
