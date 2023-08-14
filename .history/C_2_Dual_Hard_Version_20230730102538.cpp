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
        vector<int>num(n + 1) , posara(n + 1) , negara(n + 1);
        vector<pair<int,int> > possol , negsol;
        int pos = -1 , neg = -1 , allzero = true;
        for(int i = 1 ; i <= n ; i++){
            cin>>num[i];
            if(num[i] > 0){
                if(pos == -1)pos = i;
                else if(num[i] > num[pos])pos = i;
                allzero = false;
            }
            else if(num[i] < 0){
                if(neg == -1)neg = i;
                else if(num[i] < num[neg])
            }
        }
    }
}