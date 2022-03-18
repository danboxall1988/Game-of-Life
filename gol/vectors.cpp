#include <iostream>
#include <vector>
#include "cell.hpp"

using namespace std;

class T {
    public:
        int x = 1;
        void change(int);
};

void T::change(int n) {
    x = n;
}

int main(void) {
    vector<T&> v;
    T t;
    v.push_back(t);
    v[0].change(5);
    cout << v[0].x << endl;
    return 0;
}
