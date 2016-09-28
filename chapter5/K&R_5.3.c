#include<stdio.h>
/**
void strcat(char s[], char t[]){
	
	int i, j;
	i=j=0;
	
	while(s[i] != '\0')
		i++;
	
	while( (s[i++] = t[j++]) != '\0')
	;
	
}
*/
void strcat_pointer(char *s, char *t)
{
		while((*s)!='\0'){
			s++;
		}
		while( (*s++ = *t++) != '\0')
		 ;
}
 
int main(){
	
	char s[10] = "Vic";
	char t[10] = "tor";
	
	strcat_pointer(s,t);
	printf("La concatenacion de la cadena es: %s",s);
	

	return 0;

}
