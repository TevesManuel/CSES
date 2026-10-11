#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);

    int n;
    cin >> n;

    multiset<int> top;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        auto it = top.upper_bound(x);//Busca el primer elemento estrictamente mayor que x

        //top.upper_bound devuelve top.end() cuando no encuentra nada

        if (it != top.end()) {
            top.erase(it);//Borro el anterior tope de esa torre
        }//Si no elimino nada crea una nueva torre que NO "remplaza" ninguna torre anterior

        top.insert(x);//Inserto el nuevo tope de dicha torre
    }

    cout << top.size() << '\n';
}