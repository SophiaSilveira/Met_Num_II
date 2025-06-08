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

double newton(double x, double s[], double m[], int size){
    double tab[size][size];
    double termo = 1.0;

    for(int i = 0; i < size; i++){
        tab[i][0] = m[i]; 
    }

    /* calculando as diferenças divididas */
    for(int j = 1; j < size; j++){
        for(int i = 0; i < size - j; i++){
            tab[i][j] = (tab[i+1][j-1] - tab[i][j-1]) / (s[i+j] - s[i]);
        }
    }

    /* print na tabela*/
    /*  
    for(int i = 0; i < size; i++){
        printf("s = %lf | ", s[i]);
        for(int j = 0; j < size - i; j++){
            printf("%.6lf ", tab[i][j]);
        }
        printf("\n");
    }

    */
    double resultado = tab[0][0];
    for(int i = 1; i < size; i++){
        termo *= (x - s[i - 1]);
        resultado += tab[0][i] * termo;
    }

    return resultado;
};

int main(){
    double  vet_seconds[7] = {  0, 0.5, 0.8,   1, 1.4, 2, 2.7};
    double  vet_meters[7]  = {1.6,   3, 3.7, 4.8, 4.7, 3, 2.6};

    int vet_size = 7; 

    double second = 1.3;

    double result = lagrange(second, vet_seconds, vet_meters, vet_size);
    double resultNewton = newton(second, vet_seconds, vet_meters, vet_size);

    printf("Pelo metodo de lagrange para o ponto %lf foi obtido %lf \n",second, result);
    printf("Pelo metodo de Newton: f(%.1f) = %lf m\n", second, resultNewton);
    
    return 0;
}