#include "PointArray.h"
#include <stdio.h>

PointArray::PointArray(){
	size = 0;
	arreglo = new Point[size];
} 

PointArray::PointArray(int size){
	this->size=size;
	arreglo = new Point[size];
	
}

PointArray::PointArray(const Point points[], const int tam){
	size = tam;
	arreglo = new Point[tam];
	
	for(int i=0; i<tam; i++){
		arreglo[i] = points[i];
		
	}
}

PointArray::PointArray(const PointArray &pv){
	size = pv.size;
	arreglo = new Point[size];
	for(int i=0;i<size;i++){
		arreglo[i] = pv.arreglo[i];
	}

}

void PointArray::resize(int new_size){
	Point  *aux_arr = new Point[new_size];
	int tam_copy;

	if(new_size>size)
		tam_copy = size;
	else
		tam_copy = new_size;
	
	for(int i=0; i<tam_copy;i++)
		aux_arr[i] = arreglo[i];
	
	delete[] arreglo;
	size=new_size;
	arreglo = aux_arr;
	
}

 
void PointArray::push_back(const Point &p){ 
	resize(size+1);//Aqui nuestro tamanio se actualizara a size+1
	arreglo[size-1] = p;

}

void PointArray::insert(const int pos, const Point &p){
	if(pos>=0){
		resize(size+1); //Aqui nuestro tamanio se actualizara a size+1
		for(int i=size-1; i>pos;--i){
			arreglo[i] = arreglo[i-1]; //En la pos i, copiamos el "pto" almacenado en la pos anterior
		}
		//saldremos del for cuando i=pos;
		arreglo[pos] = p;
	}
	else{
		printf("Ha ingresado una posicion incorrecta :'( \n");
	}
}

void PointArray::remove(const int pos){
	if(pos>=0 && pos<size){ //simplemente validamos que se ingrese una pos valida
		for(int i=pos;i<size-2;i++){
			arreglo[i] = arreglo[i+1];//reemplazo el elemento posterior a "i" sobre este	
						  // es como aplicar un kernel de 1x2 sobre nuestro array de point desde "pos" hasta "size-2"(penultumo elemento
		}
		resize(size-1); //porque el penultimo y ultimo elemento seran iguales, por ello
		    		//reduzco el tamanio de arreglo de puntos.
	}
	else{
		printf("Ha ingresado una posicion incorrecta :'( \n");
	}
}

void PointArray::clear(){
	resize(0);
}

const int PointArray::getSize()const{
	return size;
}

Point* PointArray::searchPoint(const int pos){
	if(pos>=0 && pos<size){
		return  arreglo+pos;
	}
	return nullptr;

}


void PointArray::printPointArray(){
	printf("\n\nLos puntos que se encuentran en nuestro arreglo son:\n");
	
	for(int i=0;i<size;i++){
		printf("\nPunto en la pos %d: \n\n",i);
		arreglo[i].printPoint();
	}

} 

