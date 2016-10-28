#ifndef __POINTARRAY_H__
#define __POINTARRAY_H__

#include "Point.h"

class PointArray{
	
	private:
		int size;
		Point* arreglo;

	public:
		PointArray();
		PointArray(int size);
		PointArray(const Point points[], const int size);
		PointArray(const PointArray& pv);
		void resize(int new_size);
		void push_back(const Point &p);
		void insert(const int pos, const Point &p);		
		void clear();
		void printPointArray();
		void remove(const int position);
		const int getSize()const;
		Point* searchPoint(const int pos);
	


};

#endif
