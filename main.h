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

#define HIGHEST 1000

struct result {
	int sum, x, y;
	struct result * next;
};

struct solution {
	int sum, a, b, c, d;
};

void print_solution(struct solution * solution);

struct result * new_result(int sum, int x, int y);

struct result * push_and_check(struct result * start, struct result * new, struct solution ** solutions, int * solution_counterA);

#endif
