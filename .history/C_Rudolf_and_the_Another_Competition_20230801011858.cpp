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
bool cmp(pair< pair<int , int> , int>  one , pair< pair<int , int> , int>  two){
    if(one.first.first > two.first.first)return 1;
    if(one.first.first < two.first.first)return 0;
    if(one.first.second < two.first.second)return 1;
    if(one.first.second > two.first.second)return 0;
    if(one.second == 1)return 1;
    return 0;
} 
int main(){
    tc{
        int n , m , h;cin>>n>>m>>h;
        vector<pair< pair<int , int> , int> > vpi;
        for(int i = 0 ; i < n ; i++){
            vector<int>mo(m) , ac(m);
            for(int j = 0 ; j < m ; j++){
                cin>>mo[j];    
                ac[j] = mo[j];            
            }
            sort(all(mo));
            int cnt = 0 , scr = 0 , acr = 0;
            for(int j = 0 ; j < m ; j++){
                if(scr + mo[j] > h)break;
                cnt++;
                scr+=mo[j];
                if(j < n - 1)mo[j + 1]+=mo[j];
            }
            vpi.push_back({{cnt , scr} , i + 1});
        }
        sort(all(vpi) , cmp);
        int idx = 0;
        for(int i = 0 ; i < n ; i++){
            if(vpi[i].second == 1)
            {
                idx = i + 1;
            //    break;
            }
            cout<<i<<" "<<vpi[i].first.first<<" "<<vpi[i].first.second<<" "<<vpi[i].second<<endl;
        }
        cout<<idx<<endl;
    }
}