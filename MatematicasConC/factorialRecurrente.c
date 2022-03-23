#include<stdio.h>

//Modulo recursivo, para el factorial de un numero, de forma recursiva.
int factorialRec(int n){
	if (n < 0){
		printf("n = %d es un numero negativo, ingrese un numero positivo. \n", n);
		return 0;
	}else{
		if (n < 2) return 1;
		else return (n*factorialRec(n-1));
	}
}	

int main(){
	//definimos la variable 'numero'
	int numero;
	printf("FACTORIAL DE UN NUMERO\n");
	printf("----------------------\n");
	//pedimos y guardamo un dato en la variable 'numero'
	printf("Ingrese un numero posotivo : \n");
	scanf("%d",&numero);
	printf("El factorial del numero %d es : %d\n", numero, factorialRec(numero));
	
	return 0;
}
