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
const ll inf_ll = 1LL << 60;
const i32 mod = 1e9+7;
#define endl '\n'

//Iterative utils
#define forAB(i, a, b) for(ll i = (a); i < (ll)(b); i++)
#define forN(i, n) forAB(i, 0, (n))

//Vector utils
#define sz(vec) int((vec).size())
#define pb push_back
#define all(vec) (vec).begin(), (vec).end()

//Debug utils
#define dbg(x) std::cout << #x << " = " << (x) << ", "
#define dbgln(x) std::cout << #x << " = " << (x) << endl
#define lineN(n) forN(teves, (n)) std::cout << "="; std::cout << endl
#define line lineN(60)

#define TEVES std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);

class SegmentTreeLazy {
    private:
        std::vector<ll> arbol, lazy;
        int n;
        void propagar(int nodo, int ini, int fin){
            if(lazy[nodo] == 0) return;
            arbol[nodo] += lazy[nodo] * (fin - ini + 1);
            if(ini != fin){
                lazy[2*nodo] += lazy[nodo];
                lazy[2*nodo+1] += lazy[nodo];
            }
            lazy[nodo] = 0;
        }
    public:
        SegmentTreeLazy(int tam){
            n = tam;
            arbol.assign(4 * n, 0);
            lazy.assign(4 * n, 0);
        }
        
        void construir(std::vector<ll>& datos, int nodo, int ini, int fin) {
            if(ini == fin){
                arbol[nodo] = datos[ini];
                return;
            }
            int medio = (ini + fin) / 2;
            construir(datos, 2*nodo, ini, medio);
            construir(datos, 2*nodo + 1, medio + 1, fin);
            arbol[nodo] = arbol[2*nodo] + arbol[2*nodo + 1];
        }

        // Suma val a cada posicion del rango [l, r]
        void actualizarRango(int nodo, int ini, int fin, int l, int r, ll val){
            propagar(nodo, ini, fin);
            if(r < ini || fin < l) return;
            if(l <= ini && fin <= r){
                lazy[nodo] += val;
                propagar(nodo, ini, fin);
                return;
            }
            int medio = (ini + fin) / 2;
            actualizarRango(2*nodo, ini, medio, l, r, val);
            actualizarRango(2*nodo+1, medio+1, fin, l, r, val);
            arbol[nodo] = arbol[2*nodo] + arbol[2*nodo+1];
        }
        // Suma del rango [l, r]
        ll consultar(int nodo, int ini, int fin, int l, int r){
            propagar(nodo, ini, fin);
            if(r < ini || fin < l) return 0;
            if(l <= ini && fin <= r) return arbol[nodo];
            int medio = (ini + fin) / 2;
            return consultar(2*nodo, ini, medio, l, r) +
                consultar(2*nodo+1, medio+1, fin, l, r);
        }
};



i32 main() {
    TEVES

    i32 n, q, op, a, b, c;
    std::cin >> n >> q;
    std::vector<ll> data(n, 0);

    forN(i, n) {
        std::cin >> data[i];
    }

    SegmentTreeLazy st(n); 
    st.construir(data, 1, 0, n-1);

    forN(i, q) {
        std::cin >> op;
        std::cin >> a;
        a--;
        if (op == 1) {
            std::cin >> b;
            std::cin >> c;
            b--;
            st.actualizarRango(1, 0, n-1, a, b, c);
        } else {
            std::cout << st.consultar(1, 0, n-1, a, a) << endl;
        }
    }

    return 0;
}
