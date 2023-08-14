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
string s[3];
int len;
bool isValid(int x){
    if(x < 0)return 0;
    if(x + 1 >= len)return 0;
    if(s[0][x] == 'O' && s[0][x + 1] == 'O' && s[1][x] == 'O' && s[1][x + 1] == 'O')return 1;
    if(s[2][x] == 'O' && s[2][x + 1] == 'O' && s[1][x] == 'O' && s[1][x + 1] == 'O')return 1;
    debug(x , x + 1);
    debug(s[0] , s[1]);
    debug(s[0][x] , s[0][x + 1] ,  s[1][x] , s[1][x + 1] );
    return 0;
}
int gr[105][105];
int finder(int x1 , int x2){
    if(gr[x1][x2] != -1)return gr[x1][x2];
    if(x1 < 0 || x2 >= len)return 0;
    if(x1 >= x2)return 0;
    if(x1 + 1 == x2)return isValid(x1);
    int sol[105] = {};
    for(int i = x1 ; i < x2 ; i++){
        if(isValid(i)){        
            int ans = finder(x1 , i - 1) ^ finder(i + 1 , x2);
            if(ans <= 100)sol[ans] = 1;
            }
            else debug(i);
    }
    for(int i = 0 ; i <= 100 ; i++){
        if(sol[i] == 0){
            debug(x1 , x2  , i);
            return gr[x1][x2] = i;
        }
    }
    return 0;

}
int main(){
    tc{
        cin>>len;
        for(int i = 0 ; i < 3; i++){
            for(int j = 0 ; j < len ; j++){
                gr[i][j] = -1;
            }
            cin>>s[i];
        }
        if(finder(0 , len - 1))cs<<"Jhinuk"<<endl;
        else cs<<"Grandma"<<endl;
        
    }
}