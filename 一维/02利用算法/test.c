#include <stdio.h>
#include <stdlib.h>


void print_array(long n, double *array, char *name){
    for(long i = 0; i < n; i++){
        printf("%s[%ld] = %lf ",name, i, array[i]);
    }
    printf("\n");
}
int main(int argc, char *argv[])
{
    long n = 10;
    double *array = (double *)malloc(n * sizeof(double));
    for(long i = 0; i < n; i++){
        array[i] = i;
    }
    print_array(n, array, "h");

    return 0;
}
