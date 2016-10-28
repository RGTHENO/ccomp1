#include <iostream>
#include <vector>

typedef unsigned int ui;
typedef int i; 

using namespace std;

void printVector(vector< i > &v){
	cout<<"\n\n\tLa lista de elementos de su vector son: "<<endl<<endl;
	cout<<"\t \t";
	for( vector<i>::iterator it = v.begin(); it != v.end(); ++it){
		std::cout<<" "<<*it;
	} 
cout<<endl<<endl;
}

int main(){
	 vector<i> v(2,3); 
	
	/********************* function size ***********************/
	std::cout<<"El tamanio del vector : "<<v.size()<<endl<<endl;
	
	/************************** empty *************************/
	if(v.empty()){
		std::cout<<"Su vector esta vacio .( \n";
	}
	else std::cout<<"Enhorabuena!!! Tienes elementes almacenados en tu vector \n";
	
	/************************* push_back() ***********************/
	v.push_back(111);
	cout<<"\n\nLuego de realizar un push back \n"<<endl;
	printVector(v);
	
	/*************************   front() ************************/
	
	std::cout<<"Luego de llamar a la funcion front(): "<< v.front();
	printVector(v);
	
	/************************* pop_back()  *********************/
	v.pop_back(); // Elimina el ultimo elemento
	std::cout<<"Luego de llamar a la funcion pop_back() : \n";
	printVector(v);
	
	/************************* insert()  *********************/
	v.insert(v.begin(),10); v.insert(v.begin(),11);v.insert(v.begin()+1,12); 
	std::cout<<"Luego de llamar a la funcion insert() : \n";
	printVector(v);
	
	/************************* erase() **********************/
	v.erase(v.begin()); //recibe un intervalo de donde a donde o simplemente una posicion
	std::cout<<"Luego de llamar a la funcion erase() : \n";
	printVector(v);
	
	std::cout<<"El tamanio del vector es : "<<v.size()<<std::endl;
	
	/************************* swap() ************************/
	//void swap (vector& x); EL swap() intercambia el contenido de mi vector actual  con el de otro vector que es del mismo tipo
	//pero que podria definir en el tamanio
	
	vector<i> b(6,5);
	
	
	std::cout<<"\n\nAntes de realizar el swap()"<<std::endl;
	
	std::cout<<"el vector recien creado b(4,5) es "<<std::endl;
	printVector(b);
	
	v.swap(b);
	std::cout<<"Luego de realizar el swap(b) "<<std::endl<<endl;
	std::cout<<"El vector B quedo así :"<<std::endl;
	printVector(b);
	
	cout<<"Mi vector V : "<<endl<<endl;
	printVector(v);
	
	/******************clear()*****************/
	v.clear();
	cout<<"\n\nDespues de llamar a clear() \n"<<endl;
	printVector(v);
	cout<<"El tamanio del vector es: "<<v.size()<<endl<<endl;
	
	/****************** emplace() *************/
	//retorna un puntero al elemento que acaba de ser insertado
	
	auto it = v.emplace(v.begin(), 100 );
	v.emplace ( it, 200 );
	v.emplace ( v.end(), 300 );
	printVector(v);
	
	/******************** emplace_back() ********/
	//Retorna un elemento al final del vector, justo 
	//despues de su ultimo elemento actual
	
	v.emplace_back(31);
	printVector(v);
	
	
	
	
	return 0;
}
