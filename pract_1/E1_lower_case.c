#include<stdio.h>


int upper_lower(int c){
	return (c^32);
}



int main(){
	
		int c;
		c = getchar();
		c = upper_lower(c);
		printf("%c",c);
		  
		return 0;
}
