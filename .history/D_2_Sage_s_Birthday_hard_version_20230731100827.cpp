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
 
int main(){
    int n;cin>>n;
    int ara[n];
    vector<int>vec(n);
    for(int i = 0 ; i < n ; i++)cin>>vec[i];
    sort(all(vec));
    int idx = 0;
    for(int i = 2 ; i < n ; i+=2){
        ara[i] = vec[idx++];
    }
    for(int i = 1 ; i < n ; i+=2){
        ara[i] = vec[idx++];
    }
    int ans = 0;
    for(int i = 2 ; i < n - 1; i++){
        ans += (ara[i] < ara[i - 1] && ara[i] < ara[i + 1])
    }
}