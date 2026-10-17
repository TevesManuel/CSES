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

//Narayana Pandita ( O(n) )
/**
 * Pasos:
 *  - 1.Buscar el pivote: El primer caracter de derecha a izq que sea menor
 *      que el de su derecha, si no se encuentra ninguno,no existe permutacion
 *      siguiente.
 *  - 2.Buscar sucesor: El primer caracter de derecha a izquierda que sea
 *      estrictamente mayor al pivote.
 *  - 3.Intercambio: Intercambiamos el pivote con el sucesor.
 *  - 4.Invertir el sufijo: Invertimos el sufijo despues del pivote.
 *      Se invierte la palabra para que este el estado alfabético más bajo
 *      (orden ascendente), para no saltarnos ninguna combinación.
 */
bool next_permutation(std::string& s) {
    int n = s.length();
    int i = n - 2;

    //Encontramos el pivote
    while (i >= 0 && s[i] >= s[i + 1]) {
        i--;
    }
    if (i < 0) {
        return false; 
    }

    // Encontramos el sucesor
    int j = n - 1;
    while (s[j] <= s[i]) {
        j--;
    }

    //Intercambiamos el pivote por el sucesor
    std::swap(s[i], s[j]);

    //Invertimos el sufijo
    int izq = i + 1;
    int der = n - 1;
    while (izq < der) {
        std::swap(s[izq], s[der]);
        izq++;
        der--;
    }

    return true;
}

int main() {
    TEVES

    std::string s;
    std::string out = "";
    i32 c = 1;
    std::cin >> s;

    std::sort(all(s));

    out += s;
    out += tendl;

    // while(std::next_permutation(all(s))) {
    while(next_permutation(s)) {
        out += s;
        out += tendl;
        c++;
    }

    std::cout << c << tendl << out;

    return 0;
}