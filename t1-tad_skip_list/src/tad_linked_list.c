#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <utils.h>


void free_node(LINKED_NODE *node){

	if(!node) return;
	if(node->DNS) free(node->DNS);
	if(node->IP) free(node->IP);
	
	free(node);
}

///////////////////////////////////////////////////////////////////////////
void destroy_linked_list(TAD_LINKED_LIST *list){

	if(!list) return;
	LINKED_NODE *aux2, *aux = list->headnode;

	while(aux != NULL){
		aux2 = aux->NEXT;
		free_node(aux);
		aux = aux2; 
	}

	free(list);
}
/////////////////////////////////////////////////////////////////////////
TAD_LINKED_LIST *create_linked_list(){

	TAD_LINKED_LIST *list = (TAD_LINKED_LIST *) calloc(1, sizeof(TAD_LINKED_LIST));

return list;
}


///////////////////////////////////////////////////////////////////////////
LINKED_NODE *insertion_linked_list2(char* DNS, char* IP){

	LINKED_NODE *aux = (LINKED_NODE *)calloc(1, sizeof(LINKED_NODE));
	aux->DNS = (char*) calloc(strlen(DNS)+1, sizeof(char));
	aux->IP = (char*) calloc(strlen(IP)+1, sizeof(char));
	strcpy(aux->DNS, DNS);
	strcpy(aux->IP, IP);

return aux;
}

///////////////////////////////////////////////////////////////////////////
void insertion_linked_list(TAD_LINKED_LIST *list, char* DNS, char* IP){

	LINKED_NODE *aux = NULL;
	LINKED_NODE *aux2 = NULL;

	aux2 = list->headnode;

	aux = insertion_linked_list2(DNS, IP);
	aux->NEXT = aux2;
	list->headnode = aux;

}
///////////////////////////////////////////////////////////////////////////
char* search_linked_list(TAD_LINKED_LIST *list, char* DNS){
	
	
	LINKED_NODE *aux;
	aux  = list->headnode;

	while(aux != NULL){
		if(!strcmp(aux->DNS, DNS)) return aux->IP;
		aux = aux->NEXT;
	}

return NULL;
}

//////////////////////////////////////////////////////////////////////////////
void remove_linked_list(TAD_LINKED_LIST *list, char* DNS){
	
	LINKED_NODE *aux1, *aux2;
	aux1 = list->headnode;

	if(!strcmp(aux1->DNS, DNS)){
		list->headnode = aux1->NEXT;
		free_node(aux1);
		return;
	}

	while(aux1->NEXT != NULL){

		if(!strcmp(aux1->NEXT->DNS, DNS)){
			aux2 = aux1->NEXT;
			aux1->NEXT = aux2->NEXT;
			free_node(aux2);
			return;
		} 
		else aux1 = aux1->NEXT;
	}

	if(!strcmp(aux1->DNS, DNS)) free_node(aux1);
}