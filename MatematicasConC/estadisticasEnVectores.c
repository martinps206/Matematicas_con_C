#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
char BUFFER[4096];

// agregar los datos al vector
void array_add(int *a, int datos){
	printf("Ingresando los datos");
	for(int i = 0; i < datos; i++){
		printf("\nIngrese el el elemento %d : ", i+1);
		scanf("%d", &a[i]);
	}
}

void array_write(int *a,int datos){
	printf("\nDatos ingresados :\t[");
	for(int i=0;i<datos;i++)
		printf("  %d  ", a[i]);
	printf("]\n");
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

double array_average(int * a, int datos){
	unsigned i;
	long total = 0;
	for(i = 0; i < datos; i++) total += a[i];
	return (double) total/datos; 
}

double array_variance(int * a, int datos){
	unsigned i;
	double total = 0;
	double prom = array_average(a,datos);
	for (i = 0; i < datos; i++) total += pow((a[i] - prom),2);
	return (double)total/datos;
}

int *lower_than_average(int  *a, int datos){
	int * new = (int *) malloc(sizeof(int)*(datos+1));
	double avg = array_average(a,datos);
	unsigned i;
	*new = 0; /* Dimension del arreglo se inicializa a cero */
	for(i = 0; i < datos; i++){
		if (a[i] < avg) {
			new[(*new) + 1] = a[i]; //agregamos los elementos al arrglo new
			(*new)++;
		}
	}
	return new;
}

// gcc arrays_avg_ok.c -o array -Wall -lm
int main(int argc, char **argv){
	//char *texto;
    int datos;
    
    if (argc != 2) return 1;
    datos = atoi(argv[1]);
    //texto = argv[2];
	
	int a[datos];
	array_add(a,datos);
	array_write(a,datos);   
	printf("\n");      
	
	double promedio = array_average(a, datos);
	double varianza = array_variance(a,datos);
	int * l = lower_than_average(a, datos);

	printf("\nEl promedio de los datos es : %.2f\n",promedio);
	printf("\nLa varianza de los datos es : %.2f\n",varianza);
	printf("\nLa desviacion estandar de los datos es : %.2f\n",sqrt(varianza));
	//printf("\nValores del vector de entrada menores que el promedio\t");	
	printf("\nLos datos menores del promedio son : %s\n",array_to_s(l+1, *l));
	free(l);
	return 0;
}
