#include<stdio.h>


int strend(char *s, char *t){
	
		int tam=0;
		while((*s)!='\0'){
			//printf("El ultimo caracter de <<s>> es: %c \n",*s);
			s++;
		}
		--s; //hago que deje de apuntar al caracter NULO
		
		while((*t)!='\0'){
			//printf("El ultimo caracter de <<t>> es: %c \n",*t);
			t++;
			tam++;
		}
		//printf("EL tamanio de la cadena <<t>> es: %d \n",tam);  
		--t; //hago que deje de apuntar al caracter NULO
		
		while((*s == *t) && (tam!=0)){
			//printf(" caracter a la que apunta <<s>> antes del decremento es: %c \n",*s);
			//printf(" caracter a la que apunta <<t>> antes del decremento es: %c \n",*t);
			s--;t--;
			tam--;
		}
		//printf("EL nuevo valor de tam es: %d \n",tam);
		--t;
		//printf("A quien apunta t, rpta al caracter <<%c>> \n",*t);
		
		if (tam==0) //significa que se han hecho todas las comparaciones con la cadena t
			return 1;
		
		return 0;
}


int main(){
	
	char s[100] = "hola vic tor";
	char t[100] = "victor";
	int flag;
	flag = strend(s,t);
	printf("La respuesta es:  %d \n", flag);
	
	return 0;

}
