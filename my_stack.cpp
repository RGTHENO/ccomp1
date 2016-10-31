#include <iostream>
#include <stack>
using namespace std;


int main(){
	
	stack<int> pila;
	/************************************** push() ****************************/
	/**Inserta un elemento en la cima de la pila sobre su actual top elemento**/
	
	pila.push(12);pila.push(13);pila.push(14);
	
	
	/***************************** size() *************************************/
	cout<<"EL tamanio de la pila es: "<<pila.size()<<endl;
	
	/************************************** top() ****************************/
	/*********** Retorna una referencia al top elemento del stack ************/
	
	cout<<"Los elementos de la pila son: \n";
	 while (!pila.empty())  /*** empty() : Retorna un booleano si su tamanio esta vacio ***/
	{
		std::cout << ' ' << pila.top();
		pila.pop();          /*** pop()  : Elimina el top elemento ***/
	}
	std::cout << '\n';
	
	cout<<"El tamanio de mi pila es : "<<pila.size()<<endl<<endl;
	
	/**************************** swap(stack& x) *******************************
	 *******INtercambia los contenidos de ambas pilas **************************/
	 
	stack<int> aux; aux.push(9);aux.push(12); aux.push(15); aux.push(18);
	cout<<"El tamanio de mi aux es: "<<aux.size()<<endl<<endl;
	
	cout<<"Despues de la llamada a swap(), los tamanio de mis listas quedaron de la sgte manera: "<<endl;
	cout<<"Tamanio de Pila: "<<pila.size()<<endl;
	cout<<"Tamanio de Aux : "<<aux.size()<<endl;
	  
	/******************** emplace() ***********************************
	 * Añade un nuevo elemento sobre el top actual elemento, este nuevo elemento es construido, pasando los
	 * argumentos que recibe emplace, como argumentos del constructor de mi contenedor****/


	pila.emplace(4);pila.emplace(10);
	cout<<"Hemos realizado dos llamadas a la funcion emplace() "<<endl;
	cout<<"EL elemento en el top del stack es : "<<pila.top()<<endl;
	
	
	
	return 0;
}
