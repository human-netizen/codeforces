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
        char ch[3][3];
        int draw = true;
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++)cin>>ch[i][j];
        }
        for(int i = 0 ; i < 3 ; i++){
            if(ch[i][0] == ch[i][1] && ch[i][0] == ch[i][2] && ch[i][0] != '.'){
                cout<<ch[i][0]<<endl;
                draw = false;
            }
            if(ch[0][i] == ch[1][i] && ch[0][i] == ch[2][i] && ch[0][i] != '.'){
                cout<<ch[0][i]<<endl;
                draw = false;
            }
        }
        if(ch[0][0] == ch[1][1] && ch[0][0] == ch[2][2] && ch[0][0] != '.')cout<<ch[0][0]<<endl , draw = false;
        if(ch[0][2] == ch[1][1] && ch[0][2] == ch[2][0] && ch[0][2] != '.')cout<<ch[0][2]<<endl;

    }
}