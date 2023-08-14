#include<bits/stdc++.h>
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>&p) {return os<<'(' << p.first << ", " << p.second << ')';}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream& os, const T_container& v) {os << '{'; string sep;for(const T& x: v) os << sep << x, sep = ", "; return os << '}';}
void dbg_out() {cerr<<endl;}
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {cerr << " " << H; dbg_out(T...); }
 
#define debug(args...) cerr << "(" << #args << "):",dbg_out(args)
 
 
typedef long long ll;
#define all(x) x.begin(),x.end()
#define tc ll tt, qq=0; cin>>tt; while(qq++<tt)
#define cs cout<<"Case "<<qq<<": "
#define csl cout<<"Case "<<qq<<":"<<endl
#define uniq(vec) vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())))
 
int main(){
    ll n;cin>>n;
    bitset<200005>bs;    
    bitset<200005>as;
    as.set();
    ll ara[n];
    for(ll i = 1 ; i <= n ; i++)cin>>ara[i];
    as.reset(0);
    bs.set(1);
    ll pref[2 * n + 1] = {};
    for(ll i = 1 ; i <= n ; i++){
        pref[i] = pref[i - 1] + ara[i];
        bs |= ((bs & as)<<ara[i]);
        as.reset(i);
    }
    ll ans = 0;
    for(ll i = 1 ; i <= 2 * n ; i++){
        if(i > n)pref[i] = pref[i - 1];
        if(bs.test(i))        
        ans = max(ans , pref[i] - i + 1);
    }
    cout<<ans<<endl;
}