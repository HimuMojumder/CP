#include<bits/stdc++.h>
using  namespace std;
const int mod=1e9+7;
 struct Node {
     Node*links[26];
     bool flag=false;
     int cntEndWith;
     int cntPrefix;
     Node(){
         for(int i=0;i<26;i++){
            links[i]=NULL;
         }
         cntEndWith=0;
         cntPrefix=0;
     }
     bool containsKey(char ch){
          return (links[ch-'a']!=NULL);
     }
     void put(char ch ,Node*node){
        links[ch-'a']=node;
     }
  
     Node* get(char ch){
        return links[ch-'a'];
     }
     void increaseEnd(){
        cntEndWith++;
     }
     void increasePrefix(){
        cntPrefix++;
     }
     void deletEnd(){
        cntEndWith--;
     }
     void reducePrefix(){
        cntPrefix--;
     }
     int getEnd(){
        return cntEndWith;
     }
     int getPrefix(){
        return cntPrefix;
     }
   

 };
class Trie{
   public:
       Node*root;
   public:
   Trie (){
     root =new Node();
   }
   void insert(string &word){
        Node *node=root;
         for(int i=0;i<(int)word.size();i++){
                if(!node->containsKey(word[i])){
                    node->put(word[i],new Node());
                }
                node= node->get(word[i]);
                node->increasePrefix();
             
         }
        node->increaseEnd();    
   }
  int countWordEqualTo(string &word){
       Node* node=root;
        for(int i=0;i<(int)word.size();i++){
             if(!node->containsKey(word[i]))return 0;
                node= node->get(word[i]);
        }
        return node->getEnd();
        
   }
   int countWordStartWith(string &word){
       Node * node=root;
       for(int i=0;i<(int)word.size();i++){
          if(!node->containsKey(word[i]))return 0;
          node= node->get(word[i]);
       }
       return node->getPrefix();
   }

   // assume that whatever the caled to erase it present in the trie

   void erase(string &word){
      Node * node=root;
      for(int i=0;i<(int)word.size();i++){
         node=node->get(word[i]);
         node->reducePrefix();
      }
      node->deletEnd();
   }
    
};
int main(){
    Trie  trie; 
    string s;
    cin>>s;
    int n=s.size();
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        string tm;
        cin>>tm;
        trie.insert(tm);
    }
    // cnt number of away to construct s useing this word;

    vector<int>dp(n+1,0);
    dp[n]=1;
    for(int i=n-1;i>=0;i--){
        Node *node=trie.root;
        for(int j=i;j<n;j++){
            if(!node->containsKey(s[j]))break;
            node=node->get(s[j]);
            if(node->getEnd()){
                dp[i]=(dp[i]+dp[j+1])%mod;
            }
        }
    }
    cout<<dp[0]<<endl;
    return 0;
  
}
