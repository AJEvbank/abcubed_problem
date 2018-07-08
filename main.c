#include "main.h"

int main(int argc, char ** argv)
{
  /* Optimized solution */

  struct result ** results = (struct result **)malloc(sizeof(struct result *) * HIGHEST * HIGHEST);
  struct solution ** solutions = (struct solution **)malloc(sizeof(struct solution *) * HIGHEST);
  int x, y, solution_counterA = 0, temp_sum = 0;
  for(x = 0; x < 10; x++) {
    for(y = 0; y < 10; y++) {
      temp_sum = (x * x * x) + (y * y * y);
      results[temp_sum] = push_and_check(results[temp_sum],
                                         new_result(temp_sum,x,y),
                                         solutions,
                                         &solution_counterA);
    }
  }



  /* Brute force calculation */

  struct solution ** SOLUTIONS = (struct solution **)malloc(sizeof(struct solution *) * HIGHEST);

  int A, B, C, D, LEFT_SUM = 0, RIGHT_SUM = 0;
  int solution_counterB = 0;
  for(A = 0; A < 10; A++) {
    for(B = 0; B < 10; B++) {
      LEFT_SUM = (A * A * A) + (B * B * B);
      if (LEFT_SUM >= HIGHEST) continue;
      for(C = 0; C < 10; C++) {
        for(D = 0; D < 10; D++) {
          RIGHT_SUM = (C * C * C) + (D * D * D);
          if (RIGHT_SUM >= HIGHEST) continue;
          if (RIGHT_SUM == LEFT_SUM) {
            SOLUTIONS[solution_counterB] = (struct solution *)malloc(sizeof(struct solution));
            SOLUTIONS[solution_counterB] -> sum = LEFT_SUM;
            SOLUTIONS[solution_counterB] -> a = A;
            SOLUTIONS[solution_counterB] -> b = B;
            SOLUTIONS[solution_counterB] -> c = C;
            SOLUTIONS[solution_counterB] -> d = D;
            print_solution(SOLUTIONS[solution_counterB]);
            solution_counterB++;
          }
        }
      }
    }
  }
  printf("Total brute force solutions = %d\n",solution_counterB + 1);
  printf("Total ptimized force solutions = %d\n",solution_counterA + 1);






  return 0;
}

void print_solution(struct solution * solution) {
  printf("%d^3 + %d^3 = %d^3 + %d^3 = %d",solution -> a,solution -> b,solution -> c,solution -> d,solution -> sum);
  if ((solution -> a != solution -> c && solution -> a != solution -> d) || (solution -> b != solution -> c && solution -> b != solution -> d)) {
    printf("\t NON-EQUIVALENT SOLUTION!!\n");
  }
  else {
    printf("\n");
  }
  return;
}

struct result * new_result(int sum, int x, int y)
{
  struct result * new = (struct result *)malloc(sizeof(struct result));
  new -> sum = sum;
  new -> x = x;
  new -> y = y;
  new -> next = NULL;
  return new;
}

struct result * push_and_check(struct result * start, struct result * new, struct solution ** solutions, int * solution_counterA)
{
  if (start == NULL)
  {
    return new;
  }
  else
  {
    struct result * temp = start;
    while (temp != NULL)
    {
      if (temp -> sum == new -> sum)
      {
        solutions[*solution_counterA] = (struct solution *)malloc(sizeof(struct solution));
        solutions[*solution_counterA] -> sum = new -> sum;
        solutions[*solution_counterA] -> a = new -> x;
        solutions[*solution_counterA] -> b = new -> y;
        solutions[*solution_counterA] -> c = temp -> x;
        solutions[*solution_counterA] -> d = temp -> y;
        *solution_counterA = *solution_counterA + 1;
      }
      temp = temp -> next;
    }    
    return start;
  }
}
