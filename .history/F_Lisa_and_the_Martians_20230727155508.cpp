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

struct Node{
    Node *link[2];
    int idx = false;

    Node *nextNode(char c){
        return link[c - '0'];
    }
    Node *nextInvNode(char c){
        return link[1 - (c - '0')];
    }
    void setIdx(int idx){
        this->idx = idx;
    }

    
    
};


class Trie {

private:
    Node *root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word , int idx) {
        Node *temp = root;
        for(int i = 0 ; i < word.size() ; i++){
            if(temp->nextNode(word[i]) == NULL){
                temp->link[word[i] - '0'] = new Node();
            }
            temp = temp->nextNode(word[i]);
        }
        temp->setIdx(idx);
    }

    /** Returns if the word is in the trie. */
    pair<int,int> search(string word) {
        Node *temp = root;
        string ans , x;
        int ii;
        for(int i = 0 ; i < word.size() ; i++){
            
            if(temp->nextNode(word[i]) == NULL){
                temp = temp->nextInvNode(word[i]);
                ans += "0";
            }
            else{
                temp = temp->nextNode(word[i]);
                ans += "1";
            }
             
        }
        
        return {stoi(ans , 0 , 2) , temp->idx};
        
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    
};
int main(){
    tc{
        int n , k;cin>>n>>k;
        int ara[n + 1];
        Trie trie;
        int idx1 , idx2;
        int ans = -1;
        for(int i = 1 ; i <= n ; i++){
            int num;cin>>num;
            ara[i] = num;
            string word = "";
            for(int i = 0 ; i < k ; i++){
                if((num>>i)&1)word+="1";
                else word+="0";
            }
            reverse(all(word));
            //cout<<i<<endl;
            if(i > 1){
                pair<int,int>sol = trie.search(word);
                if(sol.first > ans){
                    idx1 = sol.second;
                    idx2 = i;
                    ans = sol.first;
                }
            }
            //cout<<i<<endl;
            trie.insert(word , i);

        }
        cout<<idx1<<" "<<idx2<<" "<<(((1 << k) - 1) ^ (ara[idx1] | ara[idx2]))<<endl;
    }
}