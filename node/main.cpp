#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20
#define max(a,b) (a>b?a:b)

typedef struct node{
	int key;// Ключ, по которому строится дерево
	struct node *left, *right;// Указатели на соседние узлы
}Node, *pNode;

pNode addnode(int x, pNode root) {
    if (!root) { // Если дерева нет, то формируем корень
        root =(pNode) malloc(sizeof(Node)); // память под узел
        if (root){
            root->key = x;   // поле данных
            root->left =  NULL;
            root->right = NULL; // ветви инициализируем пустотой
        }
    }
    else
        if (x < root->key)   // условие добавление левого потомка
            root->left = addnode(x,root->left);
        else    // условие добавление правого
            root->right = addnode(x,root->right);
    return root;
}

// нисходящий обход
void preorder(pNode root){
	if (root) { //Пока не встретится пустой узел
		printf("%d; ", root->key); //Отображаем корень дерева
		preorder(root->left); //Рекурсивная функция для левого поддерева
		preorder(root->right); //Рекурсивная функция для правого поддерева
    }
}

void postorder(pNode root) {
	if (root) { //Пока не встретится пустой узел
        postorder(root->left); //Рекурсивная функция для левого поддерева
        postorder(root->right); //Рекурсивная функция для правого поддерева
        printf("%d; ", root->key); //Отображаем корень дерева
    }
}

void inorder(pNode root){
	if (root) { //Пока не встретится пустой узел
        inorder(root->left); //Рекурсивная функция для левого поддерева
        printf("%d; ", root->key); //Отображаем корень дерева
        inorder(root->right); //Рекурсивная функция для правого поддерева
    }
}

int main(){
    pNode p,root=NULL;
    int i,k,*h=&k;
    srand(time(NULL));
    for (i=0;i<N;i++) {
        int d = rand()%70;
        root=addnode(d,root);
        printf("%d; ",d);
    }
    printf("\n ");
    puts("PREORDER");  preorder(root);  printf("\n");
    puts("POSTORDER"); postorder(root); printf("\n");
    puts("INORDER");   inorder(root);   printf("\n");
}