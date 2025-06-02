#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
using namespace std;

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
