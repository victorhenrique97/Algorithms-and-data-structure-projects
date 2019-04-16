#include <stdio.h>
#include <stdlib.h>
#include <avl.h>
#include <limits.h>

enum{
	INSERTION = 1,
	SUCCESSOR,
	PREDECESSOR,
	MAXKEY,
	MINKEY,
	PREORDER,
	INORDER,
	POSORDER
};


int main (int argc, char *argv[]){

	AVL *avl = NULL;
	int imput_lenght, operation, key, aux, flag;

	avl = (AVL *) calloc(1, sizeof(AVL));

	scanf("%d%*[ \n]", & imput_lenght);
	
	for(int i=0; i<imput_lenght; i++){
		scanf("%d%*[ \n]", &operation);

		switch(operation){

			case INSERTION:{
				scanf("%d%*[ \n]", &key);
				insertion(&(avl->root), key);
			break;
			}

			case SUCCESSOR:{
				scanf("%d%*[ \n]", &key);
				flag = 0;
				aux = search(avl->root, key, 1, &flag);
				if(flag == 0 || aux == INT_MIN) printf("erro\n");
				else printf("%d\n", aux);
			break;
			}

			case PREDECESSOR:{
				scanf("%d%*[ \n]", &key);
				flag = 0;
				aux = search(avl->root, key, 0, &flag);
				if(flag == 0 || aux == INT_MIN) printf("erro\n");
				else printf("%d\n", aux);
			break;
			}

			case MAXKEY:{
				printf("%d\n", maxkey(avl->root));
			break;
			}

			case MINKEY:{
				printf("%d\n", minkey(avl->root));
			break;
			}

			case PREORDER:{
				pre_order(avl->root);
				printf("\n");
			break;
			}

			case INORDER:{
				in_order(avl->root);
				printf("\n");
			break;
			}

			case POSORDER:{
				pos_order(avl->root);
				printf("\n");
			break;
			}
		}
	}

	free_tree(avl);

return 0;
}