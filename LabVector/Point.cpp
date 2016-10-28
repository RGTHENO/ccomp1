#include"Point.h"
#include<stdio.h>

Point::Point(){
	x = 0;
	y = 0;
}

Point::Point(int x, int y){
	this->x = x;
	this->y = y;

}

Point::Point(Point & p){
	x = p.getX();
	y = p.getY();
}
void Point::printPoint(){

	printf("Las coordenadas de nuestro Punto son :\n");
	printf("Coordenada X : %d \n",x);
	printf("Coordena Y   : %d \n",y);
}

void Point::modifyPoint(int a,int b){
	this->setX(a);
	this->setY(b);

}

void Point::setX(int x){
	this->x = x;
}

void Point::setY(int y){
	this-> y = y;
}

int Point::getX(){
	return x;
}

int Point::getY(){
	return y;
}


