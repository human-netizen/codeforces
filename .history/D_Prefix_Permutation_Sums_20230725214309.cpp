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
    tc{
        int n;cin>>n;
        int cnt[n + 1];
        int ara[n];
        int extra = -1;
        if(ara[0] > n)extra = ara[0];
        else cnt[ara[0]] = 1;
        for(int i = 1 ; i < n - 1 ; i++){
            int num = ara[i] - ara[i - 1];
            if(num > n || cnt[num] == 1){
                extra = num;
            } 
            else{
                cnt[num] = 1;
            }
        }
        int sum = 0 , miss = 0;
        for(int i = 1 ; i <= n ; i++){
            if(cnt[i] == 0)miss++ , sum++;
        }
        if(miss == 2 && sum == extra)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}