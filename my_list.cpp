#include <iostream>
#include <list>

using namespace std;
void printLista(list<int> nuevaLista){
	
	for(list<int>::iterator it = nuevaLista.begin(); it!= nuevaLista.end(); ++it) /** begin() : retorna un iterador al inicio de la lista **/
  																			      /** end()   : retorna un iterador al final de la lista **/ 
		cout<<' '<<*it;
	cout<<"\n";
}


int main(){

	int ints[] = {12,13,14,15};
	list<int> nuevaLista;
	list<int> mylista(ints,ints+4); /**Cerrado por la izq y abierto por la derecha*/
	cout<<"My lista llamada mylista contiene los sgts elementos: "<<endl;
	printLista(mylista);
		
	cout<<'\n';
	
	/************************************************/
	for(int i =0; i<4;i++){
		nuevaLista.push_back(i+1);   /** push_back() : Inserta un elemento al final de la lista **/
		
	}
	cout<<"El recorrido inverso de mi nuevaLista es: \n";
	for (std::list<int>::reverse_iterator rit=nuevaLista.rbegin(); rit!=nuevaLista.rend(); ++rit)
				std::cout << ' ' << *rit;															/** rbegin() : Retorna un iterador que apunta al ultimo
																									* 	elemento de la lista **/
																									/** rend() :  Retorna un iterador opuesto que apunta al elemento que teoricamente **/
	cout<<endl;																		 				
		 
    /******************** sort() ********************
     * Ordena los elementos de la lista */
     nuevaLista.sort();
     cout<<"Acabamos de realizar un ordenamiento de la lista \n";
     cout<<"La nueva list quedo de la sgte manera: \n";
    
     printLista(nuevaLista);
     
     cout<<"\n\n";
     cout<<"EL menor de la lista es : "<<nuevaLista.front()<<endl;      /**front() : Accede al primer de la lista **/ 
     cout<<"El mayor de la lista es : "<<nuevaLista.back()<<endl;       /**back () : Accede al ultimo de la lista **/
	

	/****************** insert(iterator pos,val) ********
	 * Inserta "val"  en la "pos" especificada *********/
	 
	 nuevaLista.insert(nuevaLista.begin(),0);
	 cout<<"Se inserto un nuevo elemento a la lista, val=0 "<<endl;
     cout<<"Luego de la insercion la lista quedo asi: \n\n";	
	 
	 printLista(nuevaLista);
	 
	 cout<<endl;
	 /**************** erase(iterator pos) *************/
	 list<int>::iterator it = nuevaLista.begin();it++;it++;
	 nuevaLista.erase(it);
	 	
	 cout<<"Luego de hacer el borrado en la pos 2 \n\n";	
	 printLista(nuevaLista);
	 cout<<"\n";
     cout<<"EL nuevo menor de la lista es : "<<nuevaLista.front()<<endl;      /**front() : Accede al primer de la lista **/ 
     cout<<"El nuevo mayor de la lista es : "<<nuevaLista.back()<<endl;       /**back () : Accede al ultimo de la lista **/
	
	 /******************* pop_back() *********************
	  * Elimina el ultimo elemento **********************/
	  nuevaLista.pop_back();
	  cout<<"Luego de llamar a pop_back(), la lista queda asi: \n";
	  printLista(nuevaLista);
	
	 /****************** pop_front() *****************
	  * Elimina el primer elemento  *****************/
	  nuevaLista.pop_front();
	  cout<<"Luego de llamar a la funcion pop_front(), la lista queda asi: \n";
	  printLista(nuevaLista);
	  
	
	 return 0;
}
