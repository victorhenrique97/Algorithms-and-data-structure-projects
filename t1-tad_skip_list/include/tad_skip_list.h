#ifndef _TAD_SKIP_LIST_H_
#define _TAD_SKIP_LIST_H_

void insertion_skip_list(TAD_SKIP_LIST *, char*, char*);
char* search_skip_list(TAD_SKIP_LIST *, char*);
TAD_SKIP_LIST *create_skip_list();
void remove_skip_list(TAD_SKIP_LIST *, char*);
void destroy_skip_list(TAD_SKIP_LIST *);

#endif