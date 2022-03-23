#include<math.h>
#include<stdio.h>
#include<stdlib.h>

double f(double x);
double bisec(double a, double b, double eps);

double f(double x){
	//return 10*(0.5*3.14*x*x-x*x-0.01*pow(x*x+0.01*0.01,1/2));
	return x*x-1;
}

double bisec(double a, double b, double eps){
	double fa, fb, m, fm;
	
	fa = f(a);
	fb = f(b);
	
	while(b-a > eps){
		m = (a+b)/2.0;
		fm = f(m);
		if(fm == 0.0) return m;
		if (fa*fm < 0.0){
			b = m;
			fb = fm;
		}else{
			a = m;
			fa = fm;	
		}
	}
	if(fabs(fa) <= fabs(fb)) return  a;
	else return b;
}

int main(){
	double a;
	double b;
	//double raiz;
	printf("\n Calcula una solucion de f(x) = 0\n");
	printf("Se empieza con a, b tales que f(a)f(b) < 0\n");
	do{
		printf("Ingrese el primer valor : ");
		scanf("%lf",&a);
		printf("Ingrese el segundo valor : ");
		scanf("%lf",&b);
	}while( a>=b || f(a)*f(b) >= 0.01);
	printf("\n raiz = %1f\n",bisec(a,b,0.01));
	return 0;	
}
