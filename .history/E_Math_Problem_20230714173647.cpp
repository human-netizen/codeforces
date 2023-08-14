#include<bits/stdc++.h>
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>&p) {return os<<'(' << p.first << ", " << p.second << ')';}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream& os, const T_container& v) {os << '{'; string sep;for(const T& x: v) os << sep << x, sep = ", "; return os << '}';}
void dbg_out() {cerr<<endl;}
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {cerr << " " << H; dbg_out(T...); }
 
#define debug(args...) cerr << "(" << #args << "):",dbg_out(args)
 
 
typedef long long ll;
#define all(x) x.begin(),x.end()
#define tc int tt, qq=0; cin>>tt; while(qq++<tt)
#define cs cout<<"Case "<<qq<<": "
#define csl cout<<"Case "<<qq<<":"<<endl
#define uniq(vec) vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())))

ll sol(ll n , ll k , ll m , ll b){
    if(n % m == 0)return 0;
    ll cur = n;
    for(int i = 1 ; i <= 64 ; i++){
        cur*=k;
        cur%=m;
        ll rem = (m - cur) % m;
        if((i * (k - 1)) >= rem)return i * b;
    }
    return INT_MAX;
}
int main(){
    tc{
        ll n , k , m , a , b;
        cin>>n>>k>>m>>a>>b;
        ll ans = 64 * a;
        for(int i = 0 ; i < 64 ; i++){
            ans = min(ans , sol(n , k , m , b) + a * i);
            debug(n);
            debug(sol(n , k , m , b));
            n/=k;
        }
        cout<<ans<<endl;
    }
    
}