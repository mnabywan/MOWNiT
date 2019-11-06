#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_blas.h>
#include <math.h>

int main() {
    srand(time(NULL));
    struct timeval t1,t2;
    double mytime;
    FILE * file = fopen("results.csv", "rw+");
    if(file == NULL){
        printf("Problems with file");
        return -1;
    }
    
    for(int j=10;j<=20000;j+=1000){
        int counter = 0;
        while(counter<10){

        
            gsl_vector *x = gsl_vector_alloc(j);
            gsl_vector *y = gsl_vector_alloc(j);
            double *res= calloc(1, sizeof(double));
            for(int i=0;i<j;i++){
                gsl_vector_set(x,i,rand()%100+1);
                gsl_vector_set(y,i,rand()%100+1);
            }
            
            gettimeofday(&t1,NULL);
            gsl_blas_ddot(x,y,res);
            gettimeofday(&t2,NULL);
            mytime = (t2.tv_sec-t1.tv_sec)*1000000+t2.tv_usec-t1.tv_usec;
            
            printf("%d,%f,0\n", j, mytime/1000000);
            fprintf(file, "%d,%f,0 \n", j, mytime/1000000);
            gsl_vector_free(x);
            gsl_vector_free(y);
            free(res);
            counter++;
        }

    }
    




for(int j=10;j<=20000;j+=1000){
        int counter=0;
        while(counter<10){
            gsl_vector *x = gsl_vector_alloc(j);
            gsl_vector *y = gsl_vector_alloc(j);
            gsl_matrix *m = gsl_matrix_alloc(j,j);
            for(int i=0;i<j;i++){
                gsl_vector_set(x,i,rand()%100+1);
                for(int k=0;k<j;k++){
                    gsl_matrix_set(m,i,k,rand()%100+1);
                }
            }

            gettimeofday(&t1,NULL);
            gsl_blas_dgemv(CblasNoTrans,1,m,x,1,y);
            gettimeofday(&t2,NULL);
            mytime = (t2.tv_sec-t1.tv_sec)*1000000+t2.tv_usec-t1.tv_usec;
            printf("%d,%f,1\n", j,  mytime/1000000);
            fprintf(file,"%d,%f,1\n", j,  mytime/1000000);
            gsl_vector_free(x);
            gsl_vector_free(y);
            gsl_matrix_free(m);
        
        
            
            counter++;
        }
    }
    fclose(file);
}