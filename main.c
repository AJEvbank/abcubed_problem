#include "main.h"

int main(int argc, char ** argv)
{



  /* Brute force calculation */

  struct solution ** solutions = (struct solution **)malloc(sizeof(struct solution *) * 10000);

  int A, B, C, D, LEFT_SUM = 0, RIGHT_SUM = 0, solution_counter = 0;
  for(A = 0; A < 10; A++) {
    for(B = 0; B < 10; B++) {
      LEFT_SUM = (A * A * A) + (B * B * B);
      if (LEFT_SUM >= 1000) continue;
      for(C = 0; C < 10; C++) {
        for(D = 0; D < 10; D++) {
          RIGHT_SUM = (C * C * C) + (D * D * D);
          if (RIGHT_SUM >= 1000) continue;
          if (RIGHT_SUM == LEFT_SUM) {
            solutions[solution_counter] = (struct solution *)malloc(sizeof(struct solution));
            (solutions[solution_counter]) => sum = LEFT_SUM;
            solutions[solution_counter] => a = A;
            solutions[solution_counter] => b = B;
            solutions[solution_counter] => c = C;
            solutions[solution_counter] => d = D;
            print_solution(&solutions[solution_counter]);
            solution_counter++;
          }
        }
      }
    }
  }
  printf("Total solutions = %d\n",solution_counter + 1);






  return 0;
}

void print_solution(struct solution * solution) {
  printf("%d^3 + %d^3 = %d^3 + %d^3 = %d\n",solution=>a,solution=>b,solution=>c,solution=>d,solution=>sum);
  return;
}
