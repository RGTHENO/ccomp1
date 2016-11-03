#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

const string vowels = " aeiou ";

string pigLatinify(const string word ){
 
	if (word.size() == 0) {// Si la cadena esta vacia
		return word;
	}

	if (vowels.find(word[0])!=-1 || vowels.find(word[0]^32)!=-1 ) { //Para cuando la cadena empiece con vocal
			return word + "-way" ;
	}
	else if(word.find ("qu")== 0 || word.find ("QU")== 0) { //find() retorna la posicion en la cual empieza la subcadena "qu"
			return word.substr(2, word.size()-2)+ "-" + word.substr(0 , 2)+"ay";
	} 
	return word.substr(1, word.size()-1)+ "-" + word[0] +"ay" ; //Para cuando la cadena empiece con cualquier consonante
}	



int main(){
	
	string word  = "QUERU"; 
	cout<<"La nueva cadena es: "<< pigLatinify(word); 
	
	
	
	return 0;
}

