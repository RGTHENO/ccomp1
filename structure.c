#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(struct key)
#define BUFSIZE 100

char buf[BUFSIZE]; /** buffer for ungetch **/
int bufp = 0;      /** next free position in buf **/
 
struct key{
	char *word;
	int count;
}keytab[2] = {
	{"alma",0},
	{"auto",0}
	//{"avion",0},
	//{"botella",0},
	//{"butaramanga",0},
	//{"gol",0},
	//{"peru",0}
			}; 

int getch(void)  /**  get a (possibly pushed back) character **/
{
	return (bufp>0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /** pus character back on input **/
{
	if(bufp >= BUFSIZE){
		printf("ungetch: too many characters\n");
	}
	else{
		buf[bufp++] = c;
	}
}



int getword(char *word,int lim){ /** getword : get next word or character from input   **/
	
	int c, getch(void);
	void ungetch(int);
	char *w = word;
	
	while( isspace( c=getch() ) )
		;
	
	if(c !=EOF){
			*w++ = c;
	}
	
	if(!isalpha(c)){
		*w = '\0';
		return c;	
	}
	
	for(; --lim; w++){
	
		if(!isalnum(*w =getch())){
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	return word[0];
	//return 4;
}


int my_binsearch(char *word, struct key tab[], int n){ /** PROTOTIPO :  int binsearch(char*,struct key*,int);**/

	int cond;
	int low =0, high = n-1, mid;
	 
	while(low <= high){
		mid = (low+high)/2;
		if( ( cond = strcmp(word,tab[mid].word) ) < 0 ){  /** strcmp : return <0 if s<t, 0 if s==t, >0 if s>t **/
			high = mid -1;
		}
		else if(cond>0){
				low = mid + 1;
		}
		else{
			return mid;
		}
	
	}
	return -1;

} /** end binary search function **/

/**count C keywords */
int main(){

	int n,i;
	char word[MAXWORD];
	
	while( getword(word,MAXWORD) !=EOF ){  /** each call to "getword" finds a word, wich is copied into the array named as its first argument **/
	
		if( isalpha(word[0]) ){   /** int isalpha(int c) : es una macro que comprube si el entero "c" pertenece al rango de letras (A o Z) or (a o z) **/
		
			if(  (n = my_binsearch(word, keytab, NKEYS) ) >= 0 ){
		
				 keytab[n].count++;
			}
		}
		
	}
	
	 
	for(i=0; i < NKEYS; i++){
		if( keytab[i].count > 0 ){
			printf("%4d %s \n", keytab[i].count, keytab[i].word);
		}
	}
	
	return 0;
} 
