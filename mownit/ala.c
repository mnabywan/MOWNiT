#include <stdio.h>
#include <gsl/gsl_blas.h>

int
main (void)
{

  

  gsl_matrix_view A = gsl_matrix_view_array(a, 2, 3);
  //gsl_matrix_view B = gsl_matrix_view_array(b, 3, 2);
  //gsl_matrix_view C = gsl_matrix_view_array(c, 2, 2);

  /* Compute C = A B */

  double d[] = {10.21, 102.241, 219.42, 12.42, 12, 124.124, 1231.42, 1241.24, 214.14, 123};
  gsl_vector_view D = gsl_vector_view_array(d,10);
  gsl_matrix_view A 

  gsl_blas_dgemv(CBLAS_TRANSPOSE, 0, A, D, 0, Y);

  printf ("[ %g, %g\n", c[0], c[1]);
  printf ("  %g, %g ]\n", c[2], c[3]);

  return 0;
}