#include<bits/stdc++.h>
#include<algorithm>
#define FIN std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0) // Upgrade std::cin & std::cout velocity
#define dt long long

void algorithm(dt a) {
    std::cout << a << " ";
    if(a == 1) return;
    if(a % 2 == 0) algorithm(a / 2);
    else algorithm(a * 3 + 1);
}

int main() {
    FIN;
    dt a;
    std::cin >> a;
    algorithm(a);
    return 0;
}