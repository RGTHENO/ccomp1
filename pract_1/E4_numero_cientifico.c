#include<stdio.h>

int potencia(n_pot){
	
	int base = 10,num=1;
	
	if(n_pot == 0)
		return 1;
		
	while(n_pot-- >=1){  //primero se evalua el valor de n_pot si es mayor o igual que 1, luego se pasa a reallizar el decremento
		num = num*base;
	}
	return num;
}

int find_number(char s[], int pos_e){
	
	int index,num=0,i;
	 
	
	for(index = pos_e - 1, i=0; index >=0; index--)
	{
		if(s[index] != '.'){
		 	num = (s[index]-48)*potencia(i++) + num;
		 }
	} 
	return num;
	
}

double generated_number(char s[], int pos_e, int pos_dot){

	int n_divis,n_multip, cant_decimales,signo_expo, exponente_e;
	double num;

	cant_decimales = pos_e - pos_dot - 1; // le restamos 1, porque tanto como pos_e y pos_dot  no se toman en cuenta
	 
	num = find_number(s,pos_e);
	signo_expo = s[pos_e+1];       								//Almacena el <<< signo del exponente de "e"  >>>
	exponente_e = s[pos_e+2]-48;   								//Almaceno a la cuanto esta elevado "e", le resto 48, porque el elemento es un caracter, cuyo valor entero esta en ASCII
	
	 
	if(signo_expo == '-'){
		n_divis = exponente_e + cant_decimales;
		
		for(;n_divis>0;n_divis--){
			num = num/10;
		}
	}
	else{
		n_multip = exponente_e-cant_decimales;
		for(;n_multip >0; n_multip--){
			num = num*10;
	    }
	 }
	return num;

}
  
double convert(char s[]){
	
	int i = 0, pos_e = -1, pos_dot = -1;
	double num;
	
	while(s[i++] != '\0'){
		
		if(s[i] == '.'){
			pos_dot = i; 										// Almacenera la posic donde s encuentra el punto
		}
		 
		if(s[i] == 'e'){ 
			pos_e = i;   										//Almacera donde esta el exponente "e"
		}
	}
	num = generated_number(s, pos_e, pos_dot);
	if(s[pos_e+1] == '+'){
		//printf("Intentare castearlo!!! \n ");
		return (int)num;
	}
	return num;	 
}


int main(){

	char s[10]= "12.458e-6";
	double num;
	
	num = convert(s);
	printf("EL numero en su estado original fue: %.9f", num); 
	
	return 0;
}


