#include <stdio.h>
#include <gsl/gsl_ieee_utils.h>
#include <math.h>

//gcc -o prog zestaw1zad3.c `gsl-config --cflags --libs`

int
main (void){

  float a = 1.1;
  float b = 2.0;
  for(int i = 1; i<200; i++){
    a = a / b;
    printf("a= ");
    gsl_ieee_printf_float(&a);
    if(isnormal(a)){
      printf(" is normal");
    }
    else printf(" is subnormal");
      
    //print(isnormal(a));
    printf("\n");

  }
}
