#include <stdlib.h>
#include <stdio.h>
#include <avl.h>
#include <limits.h>

#define max(a,b) ((a>b) ? a : b)  // define que retorna o mínimo entre 2

/////////////////////////////////////////////////////////
/*Impressão em Ordem*/
void in_order(NODE *node){

	if(!node) return;

	in_order(node->left);
	printf("%d ", node->key);
	in_order(node->right);
}

/////////////////////////////////////////////////////////
/*Impressão Pre Ordem*/
void pre_order(NODE *node){

	if(!node) return;

	printf("%d ", node->key);
	pre_order(node->left);
	pre_order(node->right);
}

/////////////////////////////////////////////////////////
/*Impressão Pós Ordem*/
void pos_order(NODE *node){

	if(!node) return;

	pos_order(node->left);
	pos_order(node->right);
	printf("%d ", node->key);
}

/////////////////////////////////////////////////////////
/*Função que procuro o ultimo nó a esquerda*/
int successor(NODE *node){

	int flag;

	if(!node) return INT_MIN;

	else{
		flag = successor(node->left);
		if(flag == INT_MIN) return node->key;
		else return flag;
	}
}

/////////////////////////////////////////////////////////
/*Função que procuro o ultimo nó a direita*/
int precessor(NODE *node){

	int flag;

	if(!node) return INT_MIN;

	else{
		flag = precessor(node->right);
		if(flag == INT_MIN) return node->key;
		else return flag;
	}
}

//////////////////////////////////////////////////////////////////////////
/*Criei uma função que pode retornar tanto o precessor quanto o sucecessor, 
sendo que, para o precessor op vale zero e para o sucessor vale 1
sendo que se for pedido o precessor, ou o elemento será o pai do ultimo 
nó a esquerda ou o nó da esquerda que tem filho mais a direita, se for 
pedido o sucessor ou o elemento será o pai do ultimo nó da direita ou o 
nó da direita que tem filho mais a esquerda */
int search(NODE *node, int key, int op, int *flag){

	int elem, aux;

	if(!node) return INT_MIN;
	
	if(key == node->key){ // encontro o elemento 
		*flag = 1;
		if(op == 0) return precessor(node->left);
		if(op == 1) return successor(node->right);
	}

	else if(key > node->key){
			aux = node->key; // pego um possivel antecessor/sucessor
			elem = search(node->right, key, op, flag);
			if(op == 0 && elem == INT_MIN) return aux; // caso seja pedido o precessor 
			//e não tenha nenhum elemento abaixo retorno o que estava acima dele
			else return elem; // se for sucessor ou precessor com elemento abaixo retono esse elemento
	}

	else if(key < node->key){
			aux = node->key; // pego um possivel antecessor/sucessor
			elem = search(node->left, key, op, flag);
			if(op == 1 && elem == INT_MIN) return aux; // caso seja pedido o sucessor
			// e não tenha nenhm elemento abaixo retorno o que estava acima dele
			else return elem; // se for precessor ou sucessor com elemento abaixo retorno esse elemento
	}

return INT_MIN;
}

/////////////////////////////////////////////////////////
/*Função que retorna a altura da árvore*/
int higher(NODE *node){

	if(!node) return -1;
	else return node->higher;
}
/////////////////////////////////////////////////////////
/*Função que libera o nó*/
void free_node(NODE *node){

	if(!node) return;

	free_node(node->left);
	free_node(node->right);
	free(node);
}

/////////////////////////////////////////////////////////
/*Função que libera a árvore*/
void free_tree(AVL *avl){

	if(!avl) return;
	if(avl->root) free_node(avl->root);
	free(avl);
}

//////////////////////////////////////////////////////////
/*Função que retorna a menor chave*/
int minkey(NODE *node){

	if(!node) return -1;

	if(!node->left) return node->key;
	else return minkey(node->left);
}

//////////////////////////////////////////////////////////
/*Função que retorna a maior chave*/
int maxkey(NODE *node){
	
	if(!node) return -1;

	if(!node->right) return node->key;
	else return maxkey(node->right);
}

//////////////////////////////////////////////////////////
/* Função que faz rotação á direita */
void rightrotation(NODE **node){

	if(!*node) return;
	NODE *aux = (*node)->left;
	(*node)->left = aux->right;
	aux->right = (*node);

	(*node)->higher = max(higher((*node)->left), higher((*node)->right))+1; // atualização das alturas
	aux->higher = max(higher(aux->left), (*node)->higher)+1;
	*node = aux;

}
//////////////////////////////////////////////////////////
/*Função que faz rotação a esquerda*/
void leftrotation(NODE **node){

	if(!*node) return;
	NODE *aux = (*node)->right;
	(*node)->right = aux->left;
	aux->left = *node;		 

	(*node)->higher = max(higher((*node)->left), higher((*node)->right))+1; // atualização das alturas
	aux->higher = max(higher(aux->right), (*node)->higher)+1;
	*node = aux; 

}
//////////////////////////////////////////////////////////
/*Função que chama rotação esquerda e direita*/
void leftrightrotation(NODE **node){
	
	if(!*node) return;
	leftrotation(&((*node)->left));
	return rightrotation(node);
}

//////////////////////////////////////////////////////////
/*Função que chama rotação direita e esquerda*/
void rightleftrotation(NODE **node){

	if(!*node) return;
	rightrotation(&((*node)->right));
	return leftrotation(node);
}

/////////////////////////////////////////////////////////
/*Função que aloca um nó e insere uma chave nele*/
NODE *create_node(int key){

	NODE *node = (NODE *) calloc(1, sizeof(NODE));
	node->key = key;

return node; 
}

//////////////////////////////////////////////////////////////
/*Função que faz a inserção em uma AVL*/
void insertion(NODE **node, int key){

	if(!*node) *node = create_node(key);

	else {
		if(key > (*node)->key){
			insertion(&((*node)->right), key); // inserção em uma AB
			if(higher((*node)->left) - higher((*node)->right) == -2){ //  checkando se precisa de rotação
				if(key > (*node)->right->key) leftrotation(node); // rotação simples 
				else rightleftrotation(node); // rotação dupla
			}
		}
			
		if(key < (*node)->key){
			insertion(&((*node)->left), key); // inserção em uma AB
			if(higher((*node)->left) - higher((*node)->right) == 2){
				if(key < (*node)->left->key)rightrotation(node); // rotação simples
				else leftrightrotation(node); // rotação dupla		
			}
		}
	}

	(*node)->higher = max(higher((*node)->left), higher((*node)->right)) + 1; // atualização da altura

}

/////////////////////////////////////////////////////////
/*Função que inicializa a árvore*/
AVL *create_tree(){

	AVL *avl = (AVL *) calloc(1, sizeof(AVL)); 

return avl;
}