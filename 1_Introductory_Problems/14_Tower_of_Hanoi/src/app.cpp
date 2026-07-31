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

int main() {
    TEVES

    i64 n;
    std::cin >> n;

    std::cout << exp2(n)-1 << "\n";

    std::vector<std::stack<int>> game(3);
    forN(i, 3){
        game[i].push(0);
    }
    forAB(i, 1, n+1) {
        game[0].push(n-i+1);
    }

    
    std::vector<int> dir = (n%2 == 0)
    ? std::vector<int>{1, 2, 0}
    : std::vector<int>{2, 0, 1};

    bool oneHasBeenMoved = false;
    i32 onePos = 0;
    while(!(game[0].top() == 0 && game[1].top() == 0 && game[2].top() == 1)) {
        // line;
        // forN(i, 3){
        //     dbg(i);
        //     dbgln(game[i].top());
        // }
        // line;
        if(oneHasBeenMoved) {
            int a = (onePos + 1) % 3;
            int b = (onePos + 2) % 3;
            if (game[a].top() == 0) {
                std::cout << b+1 << " " << a+1 << "\n";
                game[a].push(game[b].top());
                game[b].pop();
            }
            else if (game[b].top() == 0) {
                std::cout << a+1 << " " << b+1 << "\n";
                game[b].push(game[a].top());
                game[a].pop();
            }
            else if (game[a].top() < game[b].top()) {
                std::cout << a+1 << " " << b+1 << "\n";
                game[b].push(game[a].top());
                game[a].pop();
            }
            else {
                std::cout << b+1 << " " << a+1 << "\n";
                game[a].push(game[b].top());
                game[b].pop();
            }
        } else {
            game[onePos].pop();
            std::cout << onePos+1 << " " << dir[onePos]+1 << "\n";
            onePos = dir[onePos];
            game[onePos].push(1);
        }

        oneHasBeenMoved = !oneHasBeenMoved;
    }
    return 0;
}