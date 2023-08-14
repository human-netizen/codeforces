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
        int k;cin>>k;
        map<string,int>mp;
        int ara[n];
        int len = 0;
        int idx1 , idx2;
        string x;
        for(int i = 1 ; i <= n ; i++){
            int a;cin>>a;
            ara[i] = a;
            int num = ((1 << k) - 1) ^ (a);
            string str = "";
            for(int l = k - 1 ; l >= 0 ; l--){
                str += (((num>>l)&1)   + '0') ;
                if(mp[str] != 0){
                    if(str.size() > len){
                        len = str.size();
                        x = str;
                        idx1 = mp[str];
                        idx2 = i;
                    }
                }
                else{
                    mp[str] = i;
                }
            }
            

            
        }
        
        int xx = 0;
        int po = 1;
        //reverse(all(x));
        for(int i = 0 ; i < x.size() ; i++){
            xx += (po * (x[i] == '1'));
            po *= 2;
        }
        cout<<idx1<<" "<<idx2<<" "<<<ara[idx1] ^ ara[idx2]<endl;
    }
}