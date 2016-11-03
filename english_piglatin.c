#include <stdio.h>

char v[] = {'a','e','i','o','u'}, way[] = {'w','a','y'}, ay[] = {'a','y'};

void pigLatinify(char* word, char* cadena){
	char c;
	int flag =0,j,i;
	c = *word++;     /**Asigno el caracter de la pos(0) a "c", y luego incremento el puntero "word" **/
	
	for(i=0;i<5;i++){
		if(c==v[i] || c==(v[i]^32)) {flag =1;break;}
	}
	
	if(flag ==1){ //flag es igual a 1, si es que la palabra empieza con VOCAL
		cadena[0] = c; i=1;
		while(*word){ cadena[i++] = *word++; }     
		cadena[i++]='-';
		for(j=0; j<3;j++){cadena[i++] = way[j];}
		cadena[i] = '\0';
	}
	else if(c=='q'|| c==('q'^32)){ 
			word++; /**Nos saltamos un posicion más para no tomar la "u"**/
			i=0;
			while(*word){ cadena[i++] = *word++; }     
			cadena[i++] = '-';  cadena[i++] = c; cadena[i++]='u';/**Insertamos al final de nuestra nueva cadena el primer caracter de la palabra ingresada **/
			for(j=0;j<2;j++) {cadena[i++] = ay[j];}
			cadena[i] = '\0';
		}
	else{
		i=0;
		while(*word){ cadena[i++] = *word++; }     
		cadena[i++] = '-';  cadena[i++] = c;
		for(j=0;j<2;j++) {cadena[i++] = ay[j];}
		cadena[i] = '\0';
	} 

}


int main(){ 
	char *word,cadena[100];
	word = "eru";
	pigLatinify(word,cadena);
	printf("La cadena resultante es: %s \n",cadena);   
	
	return 0;
}
