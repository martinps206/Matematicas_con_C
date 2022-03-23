#include <stdio.h>
#include <math.h>

//Modulo por el ingresa la posicion de la sucesion, 
//y devuelve el termnino de la sucesion
// S(1) = 1; S(2) = 1; S(3) = 2; S(4) = 5; S(5) = 8; S(6) = 13; ...
int fib_formula(int n){
	return ((pow((1+sqrt(5))/2.0,n+1)- pow((1-sqrt(5))/2.0,n+1))/sqrt(5));
}

//El mismo modulo que el anterior, pero por el metodo recursivo
int fib_recursivo(int n){
	if(n < 3)
		return(1);
	return(fib_recursivo(n-1)+fib_recursivo(n-2));	
}

void imprimirSucesion(int cantidad){
	int i;
	printf("\t--------------------\n");
	printf("\tk \t|\t S(k)\n");
	printf("\t--------------------\n");
	for(i = 0; i < cantidad; i++){
		printf("\t%d \t|\t %d\n", i+1, fib_formula(i));
	}
	printf("\t--------------------\n");
}

int main(){
	int cantidad;
	
	printf("Ingrese la cantidad de terminos para la sucesion de Fibonacci : \t");
	scanf("%d",&cantidad);
	imprimirSucesion(cantidad);
	
	return 0;
}
