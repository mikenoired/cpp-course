#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
    pQueue pQ = createQueue();
    for (char c = 'A'; c <= 'N'; c++) {
        put(pQ, c);
        show(pQ);
    }

    cout << endl << endl;
    clearQueue(pQ);
    return 0;
}