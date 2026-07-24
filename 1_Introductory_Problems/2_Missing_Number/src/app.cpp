#include<bits/stdc++.h>
#include<algorithm>
#define FIN std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0) // Upgrade std::cin & std::cout velocity
#define dt long long

int main() {
    dt n;
    dt s;
    dt x;
    FIN;
    std::cin >> n;
    s = (n*(n+1))/2;
    for(int i = 0; i < n-1; i++) {
        std::cin >> x;
        s -= x;
    }
    std::cout << s << "\n";
    return 0;
}