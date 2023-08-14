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
int dp[101][101][2];
int res(int one , int zero , int cur){
    if(one == 0){
        dp[one][zero][0] = 1;
        dp[one][zero][1] = 0;
        return;
    }
    if(zero == 0){
        dp[one][zero][1%2] = 1;
        dp[one][zero][1 - (1 % 2)] = 0;
    }
    res(one - 1 , zero , cur);
    res(one , zero - 1 , 1 - cur);
    dp[one][zero][cur]  = !dp[one - 1][zero][cur] | 

} 
int main(){
    
}