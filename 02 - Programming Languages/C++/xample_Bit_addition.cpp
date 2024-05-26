#include <iostream>

int main() {
    bool a[]  = {0, 1, 1, 1, 1, 1, 1, 0};
    bool b[]  = {1, 0, 1, 1, 1, 1, 1, 1};
    bool c[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int r = sizeof(a);
    bool carry = false;
    for (int i = 0; i < r; ++i){
        c[i] = (a[i] xor b[i]) xor carry;
        carry = a[i]&&b[i];
    }
    if (carry) { c[sizeof(c) - 1] = true; }
    for (int i = 0; i < r + 1; ++i) {
        std::cout << c[i];
    }
}