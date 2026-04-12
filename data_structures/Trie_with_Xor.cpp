#include<bits/stdc++.h>
using namespace std;

struct  Node
{
   Node* links[2];
   bool containsKey(int bit){
      return links[bit]!=NULL;
   }
   Node* get(int bit){
         return links[bit];
   }
   void put (int bit,Node * node){
       links[bit]=node;
   }

};
class Trie{
  private: 
       Node *root;
      
    public :
     Trie (){
          root=new Node();
       }
      void insert(int num){
         Node * node=root;
           for(int i=31;i>=0;i--){
              int bit=(num>>i)&1;
              if(!node->containsKey(bit)){
                  node->put(bit,new Node());
              }
              node=node->get(bit);
           }
      }

    int getMaxXor(int num){
      Node *node=root;
      int mxnum=0;
      for(int i=31;i>=0;i--){
         int bit=(num>>i)&1;
         int opositbit=(1^bit);// or 1-bit
         if(node->containsKey(opositbit)){
            mxnum|=(1<<i);
            node=node->get(opositbit);
         }else{ 
            node=node->get(bit);
         }

      }
      return mxnum;

    }
};
int32_t main(){
      Trie trie;
    
        int n;
     cin>>n;
     vector<int>v(n);
     for(int i=0;i<n;i++)cin>>v[i];
  // insert into the trie
  
     for(int i=0;i<n;i++){
        trie.insert(v[i]);
    }
   int ans=0;
   // query for every v[i]   
   for(int i=0;i<n;i++){
       int tm=trie.getMaxXor(v[i]);
       ans=max(ans,tm);
   }
   cout<<ans<<endl;
    }

