#include<stdio.h>
#include<ctype.h> 
#include<stdlib.h>
#define BUFSIZE 100
#define               NUMBER '0'     /**Signal that a number was found */

int buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;     /* next free position in buf */


void my_getline(char *str, int lim)
{		int c;
        while ((c = getchar()) != EOF && c != '\n' && lim--) /** FIJEMONOS que fue necesario escribir << lim-- >>
															 en lugar de --lim, PORQUE la asignacion de caracter sobre nuestra cadena SE REALIZA
															 * DESPUÈS DEL TESTEO DEL WHILE **/
                *str++ = c;
        if (*str == '\n') 
                *str++ = c;
        
        *str = '\0';
}


void my_reverse(char *s){
	
	char temp, *t;
	t=s;
	
	while(*t++);
	
	--t;  //Regresa del NULO, una posicion

	while(s<t){
		temp = *t;
		*t = *s;
		*s = temp;
		s++;t--;		
	}
}

void itoa(int n, char *s){
	
	int sign;
	
	if((sign = n)<0)
		n = -n;
	 
	do
    {            //genera digitos en orden inverso
        *s++ = n % 10 + '0';   
    } while ((n /= 10) > 0);
    
    if(sign <0)
		*s++ = '-';
		
	*s ='\0';
	my_reverse(s);
	
}

int my_atoi(char *s){
	
	int num=0,sign;
	
	while(*s == 32 && s++); //Salta los espacios en blanco OJO PONER ALGO ASI  <<   while(*s++ == 32) LO QUE HACE ES PRIMERO SALTA LUEGO COMPARA 

	/**printf("EL ultimo caracter a la que apunta <<s>> es: %c \n",*s); **/
	sign = (*s == '-')?-1 : 1;
	
	if(*s == '+' || *s=='-')
		s++;
	
	while( (*s>=48) && (*s<=579) ){
		num = 10*num+(*s-'0');
		s++;
	}
	return sign*num;
	
}

int my_strindex(char *s, char *t){
		
	char *aux_s, *aux_s2, *aux_t; //Creamos un puntero auxiliar a un char
	aux_s =s; 
	aux_t=t;
	//int pos = 0;
	while(*aux_s){
		//printf("EL valor actual a la que apunta  
		if(*aux_t && *aux_t==*aux_s){ 
			aux_s2 = aux_s;
			while(*aux_t && *aux_t==*aux_s){
			// colocar a *t  en el testeo del while me sirve para cuando *t se un caracter nulo
							              //  de esa manera se rompe el bucle
			 
			                             // LO QUE HAC EL WHILE ES AVANZAR EL PUNTERO AUX (A <<s>>) HASTA QUE *aux SEA DISTINTO DE *t
			 
			//printf("Coincidieron el caracter de <<s>>: %c con el de <<t>> : %c \n",*aux_s,*aux_t); 
			aux_s++;
			aux_t++;
			//pos++;
			}
		}
		if(*aux_t == '\0' && (int)(aux_t-t) )
			return (int)(aux_s-aux_s2);
			//return pos;
		aux_s++;
	}
	
	return -1;

}

/* ungetch: COlocar un caracter al final del INPUT */

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: Demasiado caracteres \n");
    else
        buf[bufp++] = c;
}


int my_getop(char *s){
	
	int c; 
    while( (s[0] = c = getchar()) == ' ' || c == '\t')
		
    
    *(s + 1) = '\0';
    if (!isdigit(c) && c != '.')
        return c;      					 	 // not a number
        
    if (isdigit(c))    						 // collect integer part 
        while (isdigit(*++s = c = getchar()))
            ;
    if (c == '.')                            // collect fraction part
        while (isdigit(*++s = c = getchar()))
            ;
    *++s = '\0';
    
    if (c != EOF)
        ungetch(c);
        
    return NUMBER;  //señal que un numero fue encontrado
 
}


int main(){
	//char s[10] ="HOLA PERU", t[10] = "PERU";
	 
	char nvalues[10];
	//my_getline(s,10);
	//itoa(123,s);
	//printf("La cadena que contiene <<s>> es: %s",s);
	 
	//printf("El numero conseguido es: %d",my_atoi("+150"));
  
	//printf("La posicion conseguida es: %d",my_strindex(s,t));
	  
	printf("¿Ha sido coleccionado un numero? rpta : %d \n",my_getop(nvalues));
	printf("La cadena resultante es: %s",nvalues);
	
	return 0;
}
