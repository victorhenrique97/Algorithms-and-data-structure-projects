#include <stdlib.h>
#include <stdio.h>
#include <tad_linked_list.h>
#include <utils.h>
#include <tad_skip_list.h>

int main(int argc, char *argv[]){

	int operation, list_select, inputs;
	char *DNS, *IP, *DNS_result;
	TAD_LINKED_LIST *list = NULL;
	TAD_SKIP_LIST *skp = NULL;

	skp = create_skip_list();
	list = create_linked_list();

	scanf("%d%*[ \n]", &inputs);
	
	for(int i=0; i<inputs; i++){
		scanf("%d%*[ ]", &operation);

		switch(operation){

			case 0:{
				scanf("%d%*[ ]%ms%*[ ]%ms%*[ \n]", &list_select, &DNS, &IP);
				if(list_select == 1)insertion_skip_list(skp, DNS, IP);
				if(list_select == 0)insertion_linked_list(list, DNS, IP); 
				free(DNS);
				free(IP);
				break;
			}

			case 1:{
				scanf("%d%*[ ]%ms%*[ \n]", &list_select, &DNS);
				if(list_select == 1) remove_skip_list(skp, DNS);
				else if(list_select == 0) remove_linked_list(list, DNS);
				free(DNS);
				break;
			}

			case 2:{
				scanf("%d%*[ ]%ms%*[ \n]", &list_select, &DNS);
				if(list_select == 1) DNS_result = search_skip_list(skp, DNS);
				if(list_select == 0) DNS_result = search_linked_list(list, DNS);
				if(DNS_result != NULL) printf("%s\n", DNS_result);
				else printf("%d\n", -1);
				free(DNS);
				break;
			}

		}
	}

	destroy_skip_list(skp);
	destroy_linked_list(list);
}