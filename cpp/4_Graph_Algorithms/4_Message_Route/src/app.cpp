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

i32 main() {
    TEVES

    i32 n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> graph(n+1);
    std::vector<int> visited(n+1, -1);

    i32 a, b;
    forN(i, m) {
        std::cin >> a >> b;
        // dbg(a);dbg(b);
        graph[a].push_back(b);
        graph[b].push_back(a);
        // dbg(graph[a][sz(graph[a])-1]);
        // dbgln(graph[b][sz(graph[b])-1]);
    }

    std::vector<int> path;
    path.reserve(n);

    // forN(i, n+1) {
    //     std::cout << "i: " << i << " | ";
    //     forN(j, sz(graph[i])) {
    //         std::cout << graph[i][j] << " ";
    //     }
    //     std::cout << "\n";
    // }

    std::queue<int> q;
    q.push(1);
    i32 act;
    while(!q.empty()) {
        act = q.front();
        q.pop();

        // dbgln(act);

        if(act == n) {
            path.push_back(act);            
            do {
                act = visited[act];
                path.push_back(act);            
            }
            while(act != 1);
            break;
        }
        forN(i, sz(graph[act])) {
            if(visited[graph[act][i]] == -1) {
                visited[graph[act][i]] = act;
                q.push(graph[act][i]);
            }
        }
    }

    std::reverse(all(path));

    i32 pathSize = sz(path);
    if(pathSize > 0) {
        std::cout << pathSize << "\n";
        forN(i, pathSize) {
            std::cout << path[i] << " ";
        }
        std::cout << "\n";
    } else {
        std::cout << "IMPOSSIBLE\n";
    }

    return 0;
}
