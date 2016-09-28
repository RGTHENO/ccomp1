#include<stdio.h>


void revertir(char s[],int i, int j){
	int temp;
	
	if(i<j){
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		printf("Estado actual de la cadena: %s \n",s); 
		revertir(s,++i,--j);
	}
}


int main(){
	int tam = 11;
	char s[20] = "computacion";

	
	revertir(s,0,tam-1);
	printf("La cadena revertida es: %s",s);

	return 0;
}
