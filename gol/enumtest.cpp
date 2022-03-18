#include <iostream>

using namespace std;

enum s {DEAD, ALIVE};

int main(void) {
    s state = DEAD;
    if (state == DEAD)
        cout << true << endl;
}
