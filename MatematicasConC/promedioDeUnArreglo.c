#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char BUFFER[4096];

double array_avg(int * a, unsigned s){
	unsigned i;
	long total = 0;
	for(i = 0; i < s; i++) total += a[i];
	return (double) total/s; //devuelve el entero del cociente
}

/* El primer elemento es la longitud del arreglo retornado */
int *lower_than_avg(int  a[], unsigned s){
	int * new = (int *) malloc(sizeof(int)*(s+1));
	double avg = array_avg(a,s);
	unsigned i;
	*new = 0; /* Dimension del arreglo se inicializa a cero */
	for(i = 0; i < s; i++){
		if (a[i] < avg) {
			new[(*new) + 1] = a[i]; //agregamos los elementos al arrglo new
			(*new)++;
		}
	}
	return new;
}

char *array_to_s(int *a, unsigned s) {
	char *aux = BUFFER;
	unsigned long i;
	memset(aux, 0, sizeof(BUFFER));
	*aux = '[';
	for (i = 0; i < s; i++) sprintf(aux + strlen(aux), i+1 == s?"%d":"%d,", a[i]);
	strcat(aux,"]");
	return BUFFER;
}

void array_add(int a[], int cantidad){
	unsigned i;
	for(i = 0; i < cantidad; i++){
		printf("\nIngrese el el elemento %d : ", i+1);
		scanf("%d", &a[i]);
	}
}

int main(){
	
	int cantidad;
	printf("Ingrese la cantidad de elementos a ingresar : ");
	scanf("%d", &cantidad);
	int a[cantidad];
	array_add(a,cantidad);
	
	int * l = lower_than_avg(a,cantidad);
	printf("El arreglo : %s tiene como promedio  a : %10.2f\n", array_to_s(a,cantidad), array_avg(a,cantidad));
	printf("Los elementos menores que el promedio son:  %s\n", array_to_s(l+1,*l));
	free(l);
	return 0;
}
