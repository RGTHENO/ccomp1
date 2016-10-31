#include <iostream>
#include <queue>

using namespace std;

int main(){

	queue <int> cola;
	/*************************** push() *************************/
	/** Inserta un nuevo elemento en el final de la cola,
	 *  después de su último elemento.                      **/
	
	cola.push(12);cola.push(15); 
	
	/*********************** size()*******************************/
	
	cout<<"El tamanio de la cola inicialment es : "<<cola.size()<<endl;
	
	
	/************************** front() **********************/
	/** Retorna una referencia al siguiente elemento dentro de la cola */
	
	/************************* empty() **********************/
	/**T estea si la cola esta vacia  **/
	
	int i=0;
	while(!cola.empty()) // Mientras la cola no esté vacia
	{
		cout<<"elemento en la pos( "<<i<<"): "<<cola.front()<<endl;
		cola.pop();   /****** Pop()***** Remove the next element (empezando desde el principio) ****/
		i++;
	}

	cola.push(10);cola.push(30);     /******Push() : Inserta un elemento ****/

	/**************************  back() *****************************/
	/**Retorna una referencia al ultimo elemento dentro de la cola **/
	int a = cola.back();
	cout<<"Llamando a la funcion back() de queue: "<<a<<endl;
	
	/*********************** emplace() ******************************/
	/**EL nuevo elemento que va a añadir, despues de su elemento actual, es construido en
	 * su debido lugar pasando el argumento que recibe emplace como argumento del constructor
	 *  de queue**/
	cola.emplace(313);
	
	cout<<"Despues de llamar a emplace() la cola queda así : \n";
	i=0;
	while(!cola.empty()) // Mientras la cola no esté vacia
	{
		cout<<"elemento en la pos( "<<i<<"): "<<cola.front()<<endl;
		cola.pop();   /****** Pop()***** Remove the next element (empezando desde el principio) ****/
		i++;
	}
	 
	return 0;
}
