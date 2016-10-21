#include"Point.h"
#ifndef __VECTOR_H__
#define __VECTOR_H__

class Vector{
	
	private:
		Point start;	
		Point end;
	
	public:
		
		Vector(Point,Point);
		Vector(Vector &);
		

		void setStart(Point);
		void setEnd(Point);
		Point getStart();
		Point getEnd();
		double distance();

		void printVector();
};


#endif
