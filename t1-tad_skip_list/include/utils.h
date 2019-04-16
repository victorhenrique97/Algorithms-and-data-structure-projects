#ifndef _UTILS_H_
#define _UTILS_H_

typedef struct TAD_SKIP_LIST TAD_SKIP_LIST;
typedef struct SKIP_NODE SKIP_NODE;
typedef struct TAD_LINKED_LIST TAD_LINKED_LIST;
typedef struct LINKED_NODE LINKED_NODE;

struct TAD_LINKED_LIST{
	LINKED_NODE *headnode;
};

struct LINKED_NODE{
	char* DNS;
	char* IP;
	LINKED_NODE *NEXT;
};

struct TAD_SKIP_LIST{
	SKIP_NODE *headnode;
};

struct SKIP_NODE{
	char* DNS;
	char* IP;
	SKIP_NODE *NEXT;
	SKIP_NODE *DOWN;
};

#endif