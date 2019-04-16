#include <stdlib.h>
#include <utils.h>
#include <string.h>
#include <stdio.h>
#include <time.h>


//////////////////////////////////////////////////////////////////////
void destroy_node(SKIP_NODE *node){

	if(!node) return;
	if(node->DNS) free(node->DNS);
	if(node->IP) free(node->IP);
	free(node);
}
//////////////////////////////////////////////////////////////////////
void destroy_line(SKIP_NODE *node){

	if(!node) return;
	SKIP_NODE *aux2, *aux = node;

	while(aux != NULL){
		aux2 = aux->NEXT;
		destroy_node(aux);
		aux = aux2; 
	}

}
//////////////////////////////////////////////////////////////////////
void destroy_skip_list(TAD_SKIP_LIST *skp){

	if(!skp) return;

	if(skp->headnode != NULL){
		SKIP_NODE *aux = skp->headnode;
		SKIP_NODE *aux2 = NULL;

		while(aux->DOWN != NULL){
			aux2 = aux->DOWN;
			destroy_line(aux);
			aux = aux2;
		}
	destroy_line(aux);
	}

	free(skp);
}

/////////////////////////////////////////////////////////////////////
int coin_flip(){

	return rand()%2;
}
///////////////////////////////////////////////////////////////////////
SKIP_NODE *create_node(char* DNS, char* IP, int isvalid){

	SKIP_NODE *node = NULL;

	node = (SKIP_NODE *) calloc(1, sizeof(SKIP_NODE));
	if(!isvalid){
		node->DNS  = (char*) calloc(2, sizeof(char));
		node->DNS[0] = '!';
		node->DNS[1] = '\0';
	}

	else{
		node->DNS = (char*) calloc(strlen(DNS)+1, sizeof(char));
		node->IP = (char*) calloc(strlen(IP)+1, sizeof(char));
		strcpy(node->DNS, DNS);
		strcpy(node->IP, IP);
	}

return node;
}
///////////////////////////////////////////////////////////////////////////
SKIP_NODE *insertion_skip_list2(SKIP_NODE *headnode, char* DNS, char* IP){

	SKIP_NODE *head, *aux, *aux2;
	int coin;
	head = headnode;

	
	if((head->NEXT == NULL || strcmp(DNS, head->NEXT->DNS) < 0) && head->DOWN == NULL){
		aux = create_node(DNS, IP, 1);
		aux->NEXT = head->NEXT;
		head->NEXT = aux;
		
		coin = coin_flip();
		if(coin) return aux;
		else return NULL;
	}
	

	if(head->NEXT != NULL && strcmp(DNS, head->NEXT->DNS)>0){
		aux = insertion_skip_list2(head->NEXT, DNS, IP);
		return aux;
	}


	else{
		aux = insertion_skip_list2(head->DOWN, DNS, IP);
		if(aux == NULL) return NULL;

		aux2 = create_node(DNS, IP, 1);
		aux2->NEXT = head->NEXT;  
		head->NEXT = aux2;
		aux2->DOWN = aux;
		
		coin = coin_flip();
		if(coin) return aux2;
		else return NULL;

	}
	
}
/////////////////////////////////////////////////////////////////////////
void insertion_skip_list(TAD_SKIP_LIST *skp, char* DNS, char* IP){
	
	SKIP_NODE *node, *aux;
	int coin;

	if(skp->headnode == NULL) skp->headnode = create_node(NULL, NULL, 0);
		
	node = insertion_skip_list2(skp->headnode, DNS, IP);

	while(node != NULL){
		aux = create_node(NULL, NULL, 0);
		aux->DOWN = skp->headnode;
		aux->NEXT = create_node(DNS, IP, 1);
		aux->NEXT->DOWN = node;
		skp->headnode = aux;

		coin = coin_flip();
		if(coin) node = aux->NEXT;
		else node = NULL;
	}
}
///////////////////////////////////////////////////////////////////////////
char* search_skip_list(TAD_SKIP_LIST *skp, char* DNS){

	SKIP_NODE *aux;
	aux = skp->headnode;

	while(aux != NULL){
		if(!strcmp(DNS, aux->DNS)) return aux->IP;
		else if(aux->NEXT != NULL &&
			(strcmp(DNS, aux->NEXT->DNS) > 0 || strcmp(DNS, aux->NEXT->DNS) == 0)) aux = aux->NEXT;
		else aux = aux->DOWN;
	}

return NULL;
}
///////////////////////////////////////////////////////////////////////////
TAD_SKIP_LIST *create_skip_list(){

	srand(time(NULL));
	TAD_SKIP_LIST *skp;
	skp = (TAD_SKIP_LIST *) calloc(1, sizeof(TAD_SKIP_LIST));

return skp;
}
//////////////////////////////////////////////////////////////////////////////
void remove_skip_list2(SKIP_NODE *node, char* DNS){

	SKIP_NODE *aux = NULL;
	
	if(!node) return;

	if(node->NEXT != NULL && node->DOWN == NULL && !strcmp(node->NEXT->DNS, DNS)){
		aux = node->NEXT;
		node->NEXT = aux->NEXT;
		destroy_node(aux);
	}

	else {
		if(node->NEXT != NULL && strcmp(node->NEXT->DNS, DNS)<0)
			remove_skip_list2(node->NEXT, DNS);
		
		else{
			remove_skip_list2(node->DOWN, DNS);
			if(node->NEXT != NULL && !strcmp(node->NEXT->DNS, DNS)){
				aux = node->NEXT;
				node->NEXT = aux->NEXT;
				destroy_node(aux);
			}
		}
	}

}
//////////////////////////////////////////////////////////////////////////////
void remove_skip_list(TAD_SKIP_LIST *skp, char* DNS){

	SKIP_NODE *aux = skp->headnode, *aux2 = NULL;

	remove_skip_list2(aux, DNS);

	while(aux->NEXT == NULL){
		aux2 = aux;
		aux = aux->DOWN;
		destroy_node(aux2);
	}

	skp->headnode = aux;
}
