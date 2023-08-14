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
    
        int n ;cin>>n;
        string col(n + 2 , 'b');
        col[0] = col[n + 1] = 'r';
        int cnt = 0;
        int ara[n + 2];
        for(int i = 1 ; i <= n ; i++)cin>>ara[i];
        int i = 1;
        int st = 0;
        int two = 0;
        while(i <= n){
            if(ara[i] != 0){
                if(st == -1)st = i, cnt++;
                if(ara[i] == 2)two = 1;
                col[i] = 'r';
            }
            else{
                if(st){
                    if(two)col[st] = col[i] = 'r';
                }
                else{
                    if(col[st] == 'b')col[st] = 'r';
                    else col[i] = 'r';
                }
                st = two = 0;
            }
        }
        for(int i = 1 ; i <= n ; i++){
            cnt += (col[i] == 'b');
        }
        cout<<cnt<<endl;
    
}