#include <bits/stdc++.h>

#define ll long long

int main() {
    int n;
    std::cin >> n;
    ll moves = 0;
 
    ll lastNumber = 0;
    ll act;
    for(int i = 0; i < n; i++) {
        std::cin >> act;
        // std::cout << act << ", " << lastNumber << ", " << moves << std::endl;
        if(act < lastNumber) {
            moves += lastNumber - act;
        } else {
            lastNumber = act;
        }
    }

    std::cout << moves << std::endl;

    return 0;
}