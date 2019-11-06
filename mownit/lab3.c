#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_blas.h>
#include <math.h>

int **random_matrix (int N) {
    int **matrix;
    matrix = (int**) malloc(N* sizeof(int *));
    for (int i=0; i<N; i++) {
        matrix[i]= malloc(N* sizeof(int));
        for (int j=0; j<N; j++) {
            matrix[i][j] = rand()%100+1;
        }
    }
    return matrix;
}


int main() {
    srand(time(NULL));
    struct timeval t1,t2;
    double mytime;
    //printf("AAAAAAAAA");
    FILE * file = fopen("matrix2.csv", "rw+");
    if(file == NULL){
        printf("Problems with file");
        return -1;
    }
    int j =10;

    int **A;
    int **B;
    int **C;


    for(j=100; j<1000; j+=100){
        
        int counter = 0;
        while(counter<10){
            A = random_matrix(j);
            B = random_matrix(j);
            C = random_matrix(j);
            
                
                
            gettimeofday(&t1,NULL);
            for(int k = 0; k<j; k++){
                for(int g = 0; g<j; g++){
                    for(int f = 0; f<j; f++){
                        C[k][g] = C[k][g]+A[k][f]* B[f][g];
                    }
                }
            }  
            
            gettimeofday(&t2,NULL);
            mytime = (t2.tv_sec-t1.tv_sec)*1000000+t2.tv_usec-t1.tv_usec;
            printf("%d,%f,%s\n", j, mytime/1000000,"naive");
            fprintf(file, "%d,%f,%s \n", j, mytime/1000000,"naive");
            for (int i = 0; i < j; i++) {
                free(A[i]);
                free(B[i]);
                free(C[i]);
            }
            free(A);
            free(B);
            free(C);
            counter++;
        }
    
    }

    for(j=100; j<1000; j+=100){
        
        int counter = 0;
        while(counter<10){
            A = random_matrix(j);
            B = random_matrix(j);
            C = random_matrix(j);
            
                
                
            gettimeofday(&t1,NULL);
            for (int k = 0; k < j; k++){
                for (int g = 0; g < j; g++){
                    for (int f = 0; f < j; f++){
                        C[k][f] = C[k][f] + A[k][g]*B[g][f];
                    }
                }
            }  
            
            
            gettimeofday(&t2,NULL);
            mytime = (t2.tv_sec-t1.tv_sec)*1000000+t2.tv_usec-t1.tv_usec;
            printf("%d,%f,%s\n", j, mytime/1000000,"better");
            fprintf(file, "%d,%f,%s \n", j, mytime/1000000,"better");
            for (int i = 0; i < j; i++) {
                free(A[i]);
                free(B[i]);
                free(C[i]);
            }
            free(A);
            free(B);
            free(C);
            counter++;
        }
    
    }

    

    for(int j = 100; j<1000; j+=100){
        int counter =0;
        while(counter<10){   
            gsl_matrix *a = gsl_matrix_alloc(j,j);
            gsl_matrix *b = gsl_matrix_alloc(j,j);
            gsl_matrix *c = gsl_matrix_alloc(j,j);
            for(int i=0;i<j;i++){
                for(int k=0;k<j;k++){
                    gsl_matrix_set(a,i,k,rand()%100+1);
                    gsl_matrix_set(b,i,k,rand()%100+1);
                }               
            }
            
            gettimeofday(&t1,NULL);
            gsl_blas_dgemm(CblasNoTrans,CblasNoTrans,1.0,a,b,0.0,c);
            gettimeofday(&t2,NULL);

            mytime = (t2.tv_sec-t1.tv_sec)*1000000+t2.tv_usec-t1.tv_usec;
            printf("%d,%f,%s\n", j, mytime/1000000,"blas");
            fprintf(file, "%d,%f,%s \n", j, mytime/1000000,"blas");
            gsl_matrix_free(a);
            gsl_matrix_free(b);
            gsl_matrix_free(c);
            counter++;
        }
    }            
    fclose(file);
}

  

