#ifndef _TAD_LINKED_LIST_H_
#define _TAD_LINKED_LIST_H_

#include <utils.h>

void insertion_linked_list(TAD_LINKED_LIST *,char*, char*);
char* search_linked_list(TAD_LINKED_LIST *, char*);
void remove_linked_list(TAD_LINKED_LIST *, char*);
TAD_LINKED_LIST *create_linked_list();
void destroy_linked_list(TAD_LINKED_LIST *);

#endif

