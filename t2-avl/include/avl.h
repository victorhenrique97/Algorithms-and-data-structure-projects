#ifndef _AVL_H_
#define _AVL_H_

typedef struct NODE NODE;

struct NODE{
	NODE *left;
	NODE *right;
	int key;
	int higher;
};

typedef struct{
	NODE *root;
} AVL;

void free_tree(AVL *);
AVL *create_tree();
int maxkey(NODE *);
int minkey(NODE *);
void insertion(NODE **, int);
void in_order(NODE *);
void pre_order(NODE *);
void pos_order(NODE *);
int search(NODE *, int, int, int*);

#endif