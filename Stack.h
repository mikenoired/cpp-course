#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef struct Node{
  char value;
  struct Node *next;
}*pNode;

typedef struct Stack{
  pNode top;
  int len;
}*pStack;
pStack createStack();
int isEmpty(pStack pS);
void push(pStack pS, char c);
char pop(pStack pS);
void show(pStack pS);
void clearStack(pStack pS);

#endif // QUEUE_H_INCLUDED
