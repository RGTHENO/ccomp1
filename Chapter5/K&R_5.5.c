#include<stdio.h>

void myStrcopy(char *s, char *t, int n)
{	
	while((*s++=*t++) && (--n) );       /**El orden de las dos expresiones IMPORTAN!!!!!!
	// porque en la 1era expresion ya se esta asignando el caracter apuntado por "t" sobre el que tenia "s"
	//OJO: Antes que el caracter nulo apuntado por "t" sea asignado sobre "*s", el while se finalizara porque --n me dara igual a 0		  
	**/
	//while( (--n) && (*s++ = *t++) != '\0');
}

void myStrcat(char *s, char *t, int n)
{
		/**char *s1 = s;	
		while(*s++){
		//		printf("Caracter actua al que apunta s es: %c \n",*s);
		//}						  
		while(*s++ !='\0'); 
		//printf("El ultimo caracter al que apunta s es: %c \n",*s);
		
		 
		//printf("El primer caracter que asignara <<t>> sera %c \n",*t);
		//while (*s != '\0') *s++;
		**/
		while ((*++s)!= '\0');
		while( (*s++ = *t++) != '\0' && --n != 0) {      /** (*s++ = *t++) != '\0' **/ 
											  //OJO: El incremento de ambos punteros se realizan
											  // dentro del testeo del while
			//printf("EL caracter que asignaa <<t>> sera %c \n",*t);						
		} 
		/**--s;
		printf("el nuevo str %s\n",s1);
		printf("El caracter ultimo aññadido a <<s>> es : %c \n", *s);
		**/ 
		//*s = '\0'; 	 
} 

int myStrcmp(char *s, char *t, int n){
	
	while(*s == *t && s++ && t++ && --n){
		if(*s == '\0')
			return 0;
	}
	/**printf("<<s>> contiene el caracter %c \n",*s);
	printf("<<t>> contiene el caracter %c \n",*t);
	**/
	return *s-*t;

}


int main(){
	
	char s[15] = "peru";
	char t[7] = "pecolor";
	int compare;
	//myStrcopy(s,t,3);
	 
	//myStrcat(s,t,7);
	compare = myStrcmp(s,t,4);
	printf("E resutado de la comparacion es : %d",compare);
	
	//printf("La nueva cadena es : %s", s);
	
	

	return 0;
}
