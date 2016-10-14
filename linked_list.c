#include<stdio.h>
#include<stdlib.h>

struct node{

	int val;
	struct node *next;

};

struct node* cat(struct node* head, struct node* head2){

	struct node *temp;
	temp = head;

	while( temp->next != NULL){ temp = temp->next;}

	temp->next = head2;
	
	return head;
}
  
void print_list(struct node *head){
	
	struct node *t;
	t= head;
	 
	if(t==NULL)
		printf("NO HAY NINGUN ELEMENTO EN LA LISTA");
	
	while(t!= NULL)
	{
		printf("%d \n", t->val);
		t = t-> next;
	}
}

struct node* creating_node(int val){
	
	struct node* temp;
	temp = malloc(sizeof(struct node));
	temp->val  = val;
	temp->next = NULL;
	
	return temp;

}

struct node* creating_list(struct node *head, int n){
	
	struct node *prev, *cur;
	int i;
	head = malloc(sizeof(struct node));
	head->val = 1;
	prev = head;
	
	for(i = 2; i<= n; i++)
	{
		cur = malloc(sizeof(struct node));
		cur -> val = i;
		prev -> next = cur;
		prev = cur;
	} 
	prev -> next = NULL;
	
	return head;
	
}

struct node* insert_Init(struct node *head, int val){
	
	struct node* cur, *temp;
	cur = creating_node(val);
	temp = head;
	
	head = cur;
	head->next=temp;
	
	return head;
	
}


struct node* insert_End(struct node *head, int val){
	
	struct node *temp, *cur;
	cur = creating_node(val);
	temp = head;
	
	while(temp->next != NULL){ temp = temp->next;}
	
	temp->next = cur;
	return temp;


}

struct node* insert_Pos(struct node *head, int pos, int val){

	struct node *temp, *prev, *created_node, *cur;
	int tam, i;
	
	temp = head;
	tam  = 0, i=0;
	cur = head;
	created_node  = creating_node(val);
	
	 
	/**
	while(temp != NULL){ // Calcularemos el tamanio de la lista 
		
		temp = temp->next;
		tam++;
	} 
	tam++;
	*/ 
	
	if(pos <= 0){
		created_node->next = head;
		return created_node;
	} 
	
	prev = head;
	cur = head->next;
	i=1;  
	
	while(cur != NULL){

		  if(i== pos){
			
			prev-> next = created_node;
			created_node ->next =  cur;

			return head;
		  }
		  
		  i++;
		  prev = cur;
		  cur = cur->next;
	}
	
	prev->next = created_node;
	
	return head;


}



struct node* deleting_node(struct node *head, int key){

	struct node *prev, *cur;
	prev = head;
	cur = head->next;
	
	if(head->val == key){
		
		 head = prev->next;
		 free(prev);
		 return head;
	}
	
	while(cur!=NULL){
	
		if(cur->val == key){
			prev->next=cur->next;
			free(cur);
			break;
		}
		prev = cur;
		cur = cur-> next;
	}
	
	return head;

}

int main(){
	struct node *head, *head2;
	head = creating_list(head,3);
	//head = deleting_node(head,9);
	//head2 =  creating_list(head,2);
	
	//head = cat(head, head2); // ESTO YA QUEDO
	//head =  insert_Init(head,30);
	//head = insert_End(head, 313);
	
	printf("La lista inicial es: \n \n");
	print_list(head);
	head = insert_Pos(head,2,99);
	printf("Luego de la insercion, la nueva lista queda de la siguiente manera: \n \n");
	
	print_list(head);
	
	 
	return 0;
}



