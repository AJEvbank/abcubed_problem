#include "main.h"

int main(int argc, char ** argv)
{
  /* Optimized solution */

  struct result ** results = (struct result **)malloc(sizeof(struct result *) * HIGHEST);
  struct solution ** solutions = (struct solution **)malloc(sizeof(struct solution *) * HIGHEST);
  struct result * temp = NULL;
  int a, b, c, d, solution_counterA = 0, temp_sum = 0;
  int limit = (int)ceil(cbrt((double)HIGHEST));

  printf("limit = %d\n",limit);
  printf("\nOPTIMIZED\n");

  /* a and b */
  for(a = 0; a < limit; a++)
  {
    for(b = 0; b < limit; b++)
    {
      temp_sum = (a * a * a) + (b * b * b);
      if (temp_sum >= HIGHEST) break;
      results[temp_sum] = push(results[temp_sum], new_result(temp_sum,a,b));
    }
  }

  /* c and d */

  for(c = 0; c < limit; c++)
  {
    for(d = 0; d < limit; d++)
    {
      temp_sum = (c * c * c) + (d * d * d);
      if (temp_sum >= HIGHEST) break;
      temp = results[temp_sum];
      while (temp != NULL)
      {
        solutions[solution_counterA] = new_solution(temp -> sum, temp -> x, temp -> y, c, d);
        solution_counterA++;
        temp = temp -> next;
      }
    }
  }

  int i;
  printf("\nsolutions\n");
  for(i = 0; i < solution_counterA; i++)
  {
    print_solution(solutions[i]);
  }



  /* Brute force calculation */

  struct solution ** SOLUTIONS = (struct solution **)malloc(sizeof(struct solution *) * HIGHEST);

  int A, B, C, D, LEFT_SUM = 0, RIGHT_SUM = 0;
  int solution_counterB = 0;

  printf("\nBRUTE FORCE\n");
  for(A = 0; A < limit; A++) {
    for(B = 0; B < limit; B++) {
      LEFT_SUM = (A * A * A) + (B * B * B);
      if (LEFT_SUM >= HIGHEST) break;
      for(C = 0; C < limit; C++) {
        for(D = 0; D < limit; D++) {
          RIGHT_SUM = (C * C * C) + (D * D * D);
          if (RIGHT_SUM >= HIGHEST) break;
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


  printf("Total optimized force solutions = %d\n",solution_counterA);
  printf("Total brute force solutions = %d\n",solution_counterB);


  printf("\nCOMPARISON\n");
  // for(i = 0; i < solution_counterA; i++)
  // {
  //   parallel_print(solutions[i],SOLUTIONS[i]);
  // }

  




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

void parallel_print(struct solution * A, struct solution * B)
{
  printf("%d^3 + %d^3 = %d^3 + %d^3 = %d \n%d^3 + %d^3 = %d^3 + %d^3 = %d",A -> a,A -> b,A -> c,A -> d,A -> sum,
                                                                            B -> a,B -> b,B -> c,B -> d,B -> sum);
  if (A -> a == B -> b && A -> b == B -> b && A -> c == B -> c && A -> d == B -> d && A -> sum == B -> sum)
  {
    printf("\t\t-MATCH!!\n\n");
  }
  else
  {
    printf("\n\n");
  }
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

struct solution * new_solution(int sum, int a, int b, int c, int d)
{
  struct solution * new = (struct solution *)malloc(sizeof(struct solution));
  new -> sum = sum;
  new -> a = a;
  new -> b = b;
  new -> c = c;
  new -> d = d;
  return new;
}

struct result * push(struct result * start, struct result * new)
{
  if (start == NULL)
  {
    return new;
  }
  else
  {
    struct result * temp = start;
    while (temp -> next != NULL)
    {
      temp = temp -> next;
    }
    temp -> next = new;
    return start;
  }
}
