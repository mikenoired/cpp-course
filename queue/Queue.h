#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node {
    char value;
    struct Node* next;
}* pNode;

typedef struct Queue {
    pNode beg, end;
    int len;
}* pQueue;

pQueue createQueue();
int isEmptyQueue(pQueue pQ);
void put(pQueue pQ, char val);
char take(pQueue pQ);
void show(pQueue pQ);
void clearQueue(pQueue pQ);

#endif