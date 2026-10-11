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

typedef struct {
    i32 x;
    i32 y;
} Point;

i32 main() {
    TEVES

    i32 n, m;
    std::cin >> n >> m;

    std::vector<std::vector<char>> map(n, std::vector<char>(m));

    Point initialPos = {-1, -1};

    forN(i, n) {
        forN(j, m) {
            // dbg(i);
            // dbg(j);
            std::cin >> map[i][j];
            // dbgln(map[i][j]);
            if (map[i][j] == 'A') {
                initialPos.x = j;
                initialPos.y = i;
            }
        }
    }

    // forN(i, n) {
    //     forN(j, m) {
    //         std::cout << map[i][j];
    //     }
    //     std::cout << "\n";
    // }
    // line;

    if(initialPos.x == -1) {
        std::cout << "NO" << "\n";
        return 0;
    }

    std::queue<Point> q;
    q.push(initialPos);
    Point p = {-1, -1};
    char c;

    const i32 dx[4]={-1,1,0,0};
    const i32 dy[4]={0,0,-1,1};
    const char dir[4]={'L','R','U','D'};

    std::vector<std::vector<char>> path(n, std::vector<char>(m, 'i'));

    while(!q.empty()) {
        p = q.front();
        q.pop();
        if(p.x < 0 || p.x >= m || p.y < 0 || p.y >= n)
            continue;
        c = map[p.y][p.x];
        if(c == '#' || c == 'v')
            continue;
        if(c == 'B') {
            break;
        }
        map[p.y][p.x] = 'v';
        
        // forN(i, n) {
        //     forN(j, m) {
        //         std::cout << map[i][j];
        //     }
        //     std::cout << "\n";
        // }
        // dbgln(p.path);
        // line;

        forN(k, 4) {
            i32 nx = p.x+dx[k];
            i32 ny = p.y+dy[k];
            if(nx>=0 && nx<m && ny>=0 && ny<n && map[ny][nx]!='#' && map[ny][nx] != 'v') {
                q.push({nx, ny});
                path[ny][nx] = dir[k];
            }
        }
    }

    // dbgln(map[p.y][p.x]);

    // forN(i, n) {
    //     forN(j, m) {
    //         std::cout << path[i][j];
    //     }
    //     std::cout << "\n";
    // }

    if(map[p.y][p.x] != 'B')
        std::cout << "NO" << std::endl;
    else {
        std::string strPath = "";
        c = path[p.y][p.x];
        while(c != 'i') {
            strPath += c;
            if(c == 'U') {
                p.y += 1;
            } else if(c == 'D') {
                p.y -= 1;
            } else if(c == 'R') {
                p.x -= 1;
            } else if(c == 'L') {
                p.x += 1;
            }
            // dbgln(c);
            c = path[p.y][p.x];
        }
        std::reverse(all(strPath));
        std::cout << "YES" << "\n" << strPath.size() << "\n" << strPath << "\n";
    }

    return 0;
}
