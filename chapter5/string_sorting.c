#include<stdio.h>
#include<string.h>
#define MAXLINES 5000    /** max #lines to be sorted */
#define MAXLEN 1000      /** MAX LENGTH OF ANY INPUT LINE **/
#define ALLOCSIZE 1000  /** size of available space */

static char allocbuf[ALLOCSIZE];   /**storage for alloc **/
static char *allocp = allocbuf;    /** next free position **/

char *lineptr[MAXLINES];  /** pointer to text lines**/

char* my_alloc(int n){

	if(allocbuf + ALLOCSIZE - allocp >= n){
			allocp += n;
			return allocp-n; /**old p */
	}
	return 0;
}

int my_getline(char *str, int lim)
{		 
		int c, n=0;
        while ((c = getchar()) != EOF && c != '\n' && lim--){ /** FIJEMONOS que fue necesario escribir << lim-- >>
															 en lugar de --lim, PORQUE la asignacion de caracter sobre nuestra cadena SE REALIZA
		
															 * DESPUÈS DEL TESTEO DEL WHILE **/
                *str= c;
                str++;
                n++;
       }
       *str = '\0'; 
       return n;                                            /** <<n>> representa el tamanio de la cadena **/     
           
}

int readlines(char *lineptr[], int maxlines){  // lineptr es un array de MAXLINES elementos, donde c/elemento es un puntero a un char
	
	int len, nlines;
	char *p, line[MAXLEN];	 
	
	nlines = 0; 
	while( (len=my_getline(line, MAXLEN)) >0){              /** <<line>> es un cadena de caracteres 	
															* getline retorna el tamanio de la cadena leida
															* 
															* **/
		if( (nlines >= maxlines) || (p=my_alloc(len+1)) == NULL){  // nlines es mayor o "IGUAL A CERO" porqe <<nlines>> se inicializa en cero
			return -1;
		} /** fin if **/
		else{
			strcpy(p,line);
			
			lineptr[nlines++] = p;
		}/**Fin else **/
	}
	return nlines;
	
}

void writelines(char *lineptr[], int nlines){ 
	
	while(nlines-- >0){
		printf("%s \n", *lineptr); 
		lineptr++;
	}
}
  
void my_swap(char *v[],int i, int j)
{
	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
 
int my_strcmp(char *s, char *t){
	
	while(*s == *t && s++ && t++){
		if(*s == '\0'){
			return 0;
		}
	} 
	return *s-*t;

}
void my_qsort(char *v[], int left, int right){
	
	int i, last;
	
	if(left >=right){   /** do nothing if array contains **/
		return;
	}
	my_swap(v, left, (left+right)/2);
	last = left;
	 
	for(i=left+1; i<=right; i++){
		if(my_strcmp(v[i],v[left]) < 0){
				my_swap(v, ++last, i);
		}
	}
	my_swap(v,left,last);
	my_qsort(v,left,last-1);
	my_qsort(v,last+1,right);
}

 
int main(){
	
	int nlines;
	if( (nlines = readlines(lineptr, 4)) >=0){
		my_qsort(lineptr,0,nlines-1);
		printf("\n\nLas cadenas ordenadas quedan de la sgte forma: \n\n");
		writelines(lineptr,nlines);
		return 0;
	}
	
	else{
		printf("error: input too big to sort \n");
		return 1;
	}
	return 0;
} 
