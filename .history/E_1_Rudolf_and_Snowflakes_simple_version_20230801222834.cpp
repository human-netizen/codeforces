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
int res(int x , int n , int orig){
    int cur = 1;
    for(int i = 1 ; i < n; i++){
        cur *= x;
        if(cur > 1e11)break;
    }
    cur-=1;
    cur/=(n - 1);
    if(cur == orig)return 0;
    if(cur > orig)return 1;
    return -1;
}
int binSearch(int lo , int hi , int x , int orig){
    if(lo == hi)return lo;
    int mid = (lo + hi) / 2;
    int result = res(x , mid , orig);
    if(result == 0)return lo;
    if(result == -1)return binSearch(lo , mid , x , orig);
    return binSearch(mid , hi , x , orig);
} 
int main(){
    tc{
        ll n;cin>>n;
        if(n <= 5)cout<<"NO"<<endl;
        bool res = false;
        for(int i = 2 ; i * i <= n ; i++){
            int xn = binSearch(2 , 64 , i , n);
            if(xn == orig)res =
        }
    }
}