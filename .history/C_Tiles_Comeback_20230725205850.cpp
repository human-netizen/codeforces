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
        int n , k;cin>>n>>k;
        int ara[n];
        for(int i = 0 ; i < n ; i++)cin>>ara[i];
        int cnt[n + 1] = {};
        int l = 0 , r = n - 1;
        int cc = 0;
        while(l < n){
            if(ara[l] == ara[0])cc++;
            if(cc == k)break;
        }
        l++;
        cc = 0;
        while(r >= 0){
            if(ara[r] == ara[n - 1])cc++;
            if(cc == k)break;
        }
        r--;
        int lagbe = k - 2;
        if(r < l)cout<<"NO"<<endl;
        else{
            vector<int>tilNow;

            if(int i = l ; i <= r && lagbe; i++){
                tilNow.push_back(ara[i]);
                cnt[ara[i]]++;
                if(cnt[ara[i]] == k){
                    lagbe = false;
                    for(int til:tilNow)cnt[]
                }
            }
        }
    }
}