#include "Vector.h"
#include<stdio.h>

int main(){
	Point p1(4,4),p2(6,6);
	Vector v1(p1,p2);
	

	v1.printVector();	
	printf("\nLa distancia de los puntos de nuestro vector es: %f \n .) \n",v1.distance());
       
	

	return 0;
}
