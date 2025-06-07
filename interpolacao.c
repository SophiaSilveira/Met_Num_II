#include <stdio.h>
#include <stdlib.h>

double lagrange(double x, double s[], double m[], int size){

    double total = 0.0;

    for(int i = 0; i < size; i++){
        double numerador = 1.0;
        double denominador = 1.0;

        for(int j = 0; j < size; j++){
            if(i == j) continue;
            numerador *= (x - s[j]);
            denominador *= (s[i] - s[j]);
        }

        total += m[i] * (numerador/denominador);
    }

    return total;
};

int main(){
    double  vet_seconds[7] = {  0, 0.5, 0.8,   1, 1.4, 2, 2.7};
    double  vet_meters[7]  = {1.6,   3, 3.7, 4.8, 4.7, 3, 2.6};

    int vet_size = 7; 

    double second = 1.3;

    double result = lagrange(second, vet_seconds, vet_meters, vet_size);

    printf("Pelo metodo de lagrange for obtido %lf \n", result);

    return 0;
}