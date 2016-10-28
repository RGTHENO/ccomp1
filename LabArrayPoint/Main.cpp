#include "PointArray.h"
#include "Point.h"
#include<stdio.h>

int main(){
	Point p1(2,5), p2(6,10), p3(1,0),p4;
	Point vp[]={p1,p2};
	PointArray array(3);
	Point* foundit;
	int pos_found=2, pos_insert = 1, pos_remove = 1;


	PointArray array2(vp,2);
	printf("\n\t\tNuestro array recien creado es:\n");
	array2.printPointArray();
	
	array2.push_back(p3);
	printf("\n\t\tNuestro array luego del pushback\n");
	array2.printPointArray();

	array2.insert(pos_insert,p4);//p4 es un punto cuyos valores son (0,0)
	printf("\n\t\tNuestro array luego de la insercion en la pos (%d):\n",pos_insert);
	array2.printPointArray();

	array2.remove(pos_remove);
	printf("\n\t\t Nuestro array luego de remover el punto de la pos(%d):\n",pos_remove);
	array2.printPointArray();

	printf("\n\t\tEl tamanio de nuestro array es: %d\n",array2.getSize());
	foundit = array2.searchPoint(2);

	printf("\n\t\tEl punto que se almacena en la pos (%d) es: \n", pos_found);
	if(foundit !=nullptr){
		printf("\nEl punto en la pos (%d) solicitada es:\n",pos_found);
		foundit->printPoint(); 
	}
	else{
		printf("\nEl punto no existe\n");
	}

	array2.clear();
	printf("\n\n\t\tNuestro array luego de llamar a clear()\n ");
	array2.printPointArray();

	return 0;
}
