#include<stdio.h>
#include "Vector.h"
#include <math.h>

Vector::Vector(Point start, Point end){
	this->start = start;
	this->end = end;
}

Vector::Vector(Vector &v){
	this->start = v.getStart();
	this->end = v.getEnd();
}

void Vector::setStart(Point start){
	this->start = start;

}

void Vector::setEnd(Point end){
	this->end  = end;

}

Point Vector::getStart(){
	return start;

}

Point Vector::getEnd(){
	return end;
}

void Vector::printVector(){
	printf("\nPoint Start: \n");
	start.printPoint();
	printf("\nPoint End: \n");
	end.printPoint();

}

double Vector::distance(){
        return sqrt( pow(( end.getY()-start.getY() ),2)+pow(( end.getX() - start.getX() ),2 ));
//	return 0.1;
}
