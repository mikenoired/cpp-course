#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct Node{
  char value;
  struct Node *next;
}*pNode;

typedef struct Stack{
  pNode top;
  int len;
}*pStack;

pStack createStack(){
  pStack pS=(pStack) malloc(sizeof(pStack));
  if(pS){
    pS->top=NULL;
    pS->len=0;
    return pS;
  }
  else exit(1);
}
int isEmpty(pStack pS){
  if (pS->top && pS->len) return 0;
  return 1;
}

void push(pStack pS,char c){
	pNode p= (pNode)malloc (sizeof(Node));
	p->value=c;
	p->next=pS->top;
	pS->top=p;
	pS->len++;
}

char pop(pStack pS){
	pNode p=pS->top;
	char c=p->value;
	pS->top=p->next;
	free(p);
	pS->len--;
	return c;
}

void show(pStack pS){
	pNode p=pS->top;
	if(isEmpty(pS)) cout<<"Stack is empty\n";
	while(p){
		printf("\t%c\t%p", p->value,p->next);
		p=p->next;
	}
  cout<<endl;
}

void clearStack(pStack pS){
  while (!isEmpty(pS)) pop(pS);
  free(pS);
}

int main() {
  pStack pS = createStack();
  char c;
  for (c = 'A'; c <= 'D'; c++) {
    push(pS, c);
  }
  show(pS);
  cout << endl;
  while(!isEmpty(pS)) {
    show(pS);
    pop(pS);
  }
  clearStack(pS);
  return 0;
}
