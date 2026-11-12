/* AUTHOR: Manuel Tomas Teves */

#include <bits/stdc++.h>

//Types
typedef long long ll;
typedef long double ld;
typedef int8_t   i8;          // -128 a 127
typedef uint8_t  u8;          // 0 a 255
typedef int16_t  i16;         // -32.768 a 32.767
typedef uint16_t u16;         // 0 a 65.535
typedef int32_t  i32;         // -2.147.483.648 a 2.147.483.647
typedef uint32_t u32;         // 0 a 4.294.967.295
typedef int64_t  i64;         // -9.223.372.036.854.775.808 a 9.223.372.036.854.775.807
typedef uint64_t u64;         // 0 a 18.446.744.073.709.551.615
typedef __int128_t  i128;     // -(2^127) a 2^127 - 1
typedef __uint128_t u128;     // 0 a 2^128 - 1
typedef float       f32;      // ±3.402823466 × 10^38
typedef double      f64;      // ±1.797693134 × 10^308
typedef __float128  f128;     // ±1.189731495 × 10^4932

//Constants
const i32 inf = 1 << 30;
// const ll inf = 1LL << 60;
const i32 mod = 1e9+7;

//Iterative utils
#define forAB(i, a, b) for(ll i = (a); i < (ll)(b); i++)
#define forN(i, n) forAB(i, 0, (n))

//Vector utils
#define sz(vec) int((vec).size())
#define pb push_back
#define all(vec) (vec).begin(), (vec).end()

//Debug utils
#define dbg(x) std::cout << #x << " = " << (x) << ", "
#define dbgln(x) std::cout << #x << " = " << (x) << std::endl
#define lineN(n) forN(teves, (n)) std::cout << "="; std::cout << std::endl
#define line lineN(60)

#define TEVES std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);

#define undef -1

std::vector<ll> dijkstra(
    std::vector<std::vector<std::pair<ll, ll>>> &graph,
    i32 origin
) {
    int n = graph.size();

    std::vector<ll> distance(n, LLONG_MAX);

    std::priority_queue<
        std::pair<ll, i32>,
        std::vector<std::pair<ll, i32>>,
        std::greater<>
    > tail;

    distance[origin] = 0;
    tail.push({0, origin});

    while(!tail.empty()) {
        auto [d, current] = tail.top();
        tail.pop();

        if(d > distance[current])
            continue;

        for(auto [neighbor, weight] : graph[current]) {

            if(distance[current] + weight < distance[neighbor]) {

                distance[neighbor] = distance[current] + weight;

                tail.push({distance[neighbor], neighbor});
            }
        }
    }

    return distance;
}

i32 main() {
    TEVES

    i32 n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<ll, ll>>> graph(n+1);

    forN(i, m) {
        i32 from;
        ll to, weight;

        std::cin >> from >> to >> weight;

        graph[from].push_back({to, weight});
    }

    std::vector<ll> out = dijkstra(graph, 1);

    forAB(i, 1, n+1) {
        std::cout << out[i] << " ";
    }

    std::cout << "\n";

    return 0;
}