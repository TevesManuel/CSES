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
#define tendl '\n'

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

ll r(
        std::vector<i32>& apples,
        i32 index,
        std::vector<i32>& A,
        std::vector<i32>& B
    ) {
        // forN(i, A.size()) {
        //     i == (ll) A.size() - 1 ? dbgln(A[i]) : dbg(A[i]);
        // }
        // forN(i, B.size()) {
        //     i == (ll) B.size() - 1 ? dbgln(B[i]) : dbg(B[i]);
        // }
        // line;
        
        if(index == (i32)apples.size()) {
            ll accA = std::accumulate(all(A), 0LL);
            ll accB = std::accumulate(all(B), 0LL);
            // dbgln(accA);
            // dbgln(accB);
            return accA > accB ? accA - accB : accB - accA;
        }
        ll min = inf;
        i32 next = index + 1;
        A.push_back(apples[index]);
        min = r(apples, next, A, B);
        A.pop_back();
        B.push_back(apples[index]);
        min = std::min(min, r(apples, next, A, B));
        B.pop_back();
        return min;
}

int main() {
    TEVES

    i32 n;
    std::cin >> n;
    std::vector<i32> vec(n);
    forN(i, n) {
        std::cin >> vec[i];
    }

    std::vector<i32> A;
    std::vector<i32> B;

    std::cout << r(vec, 0, A, B) << tendl;

    return 0;
}