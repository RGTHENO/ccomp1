#include<stdio.h>

int count_pos(char s[], int c){
	
	int i=0, index=-1; 
	
	while(s[i]!= '\0'){ 
		if(s[i] == c){
			index=i; 
		}		
		i++;
	}
	return index;
}

int main(){
	
	char s[10] = "victvr";
	int  index, c;	
	printf("Ingrese el caracter a buscar:");
	c=getchar();
	index = count_pos(s,c);
	printf("Ultima posicion encontrada : %d", index);
	
	return 0;
}
