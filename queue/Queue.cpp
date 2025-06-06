#include <cstdio>
#include <cstdlib>
#include "Queue.h"

pQueue createQueue() {
    pQueue pQ = (pQueue)malloc(sizeof(Queue));
    pQ->beg = NULL;
    pQ->end = NULL;
    pQ->len = 0;
    return pQ;
}

int isEmptyQueue(pQueue pQ) {
    return !(pQ->beg && pQ->end && pQ->len);
}

void put(pQueue pQ, char val) {
    pNode p = (pNode)malloc(sizeof(Node));
    p->next = NULL;
    p->value = val;
    if (pQ->end) {
        pQ->end->next = p;
    } else {
        pQ->beg = p;
    }
    pQ->end = p;
    pQ->len++;
}

char take(pQueue pQ) {
    pNode p = pQ->beg;
    char c = p->value;
    pQ->beg = p->next;
    free(p);
    pQ->len--;
    return c;
}

void show(pQueue pQ) {
    pNode p = pQ->beg;
    if (isEmptyQueue(pQ)) {
        puts("Queue is empty");
        return;
    }
    while (p) {
        printf("  %c ", p->value);
        p = p->next;
    }
    printf("\n");
}

void clearQueue(pQueue pQ) {
    while (!isEmptyQueue(pQ)) {
        take(pQ);
        show(pQ);
    }
}