/*
Aluna: Ana Laura Fernandes de Oliveira
Matrícula: 680715
Professor: Henrique Cota

A diretiva pragma omp parallel for foi utilizada para que as iterações do loop 
fossem divididas entre o grupo de threads geradas pela diretiva
pragma omp parallel. 

Tempo real sequencial: 2m43.728s
Tempo real sequencial: 0m45.349s
Speed-up: tempo sequencial/tempo paralelo = 3,61039935
*/
#include <stdio.h>
#include <stdlib.h>

void mm(double* a, double* b, double* c, int width) 
{
 #pragma omp parallel for
 for (int i = 0; i < width; i++) {
    #pragma omp parallel for
    for (int j = 0; j < width; j++) {
      double sum = 0;
      #pragma omp parallel for
      for (int k = 0; k < width; k++) {
	    double x = a[i * width + k];
	    double y = b[k * width + j];
	    sum += x * y;
      }
      c[i * width + j] = sum;
    }
  }
}

int main()
{
  int width = 2000;
  double *a = (double*) malloc (width * width * sizeof(double));
  double *b = (double*) malloc (width * width * sizeof(double));
  double *c = (double*) malloc (width * width * sizeof(double));

  for(int i = 0; i < width; i++) {
    for(int j = 0; j < width; j++) {
      a[i*width+j] = i;
      b[i*width+j] = j;
      c[i*width+j] = 0;
    }
  }

  mm(a,b,c,width);

  //  for(int i = 0; i < width; i++) {
  //  for(int j = 0; j < width; j++) {
  //    printf("\n c[%d][%d] = %f",i,j,c[i*width+j]);
  //  }
  // }
}