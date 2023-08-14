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
    ll k;cin>>k;
    ll ara[10];
    for(ll i = 1 ; i <= 40 ; i++){
        ll ans = 1;
        for(ll j = 0 ; j < 10 ; j++){
            ans *= i;
        }
        cout<<ans<<endl;
        if(ans >= k){            
            for(ll l = 0 ; l < 10 ; l++){
                ara[l] = i;
                if((ans/i) * (i - 1) >= k){
                    ans/=i;
                    ans *= (i - 1);
                    ara[l] = i - 1;
                }
            }
            break;
        }
    }
    string s = "codeforces";
    for(ll i = 0 ; i < 10 ; i++){
        for(ll j = 0 ; j < ara[i] ; j++){
            cout<<s[i];
        }
    }
    cout<<endl;

}