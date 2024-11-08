#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   
    vector<int> getMaximumXor(vector<int>& v, int mb) {
         vector<int>dp(21,1);
         dp[0]=1;
         for(int i=1; i<21; i++){
            dp[i]=2*dp[i-1];
         }

         int maxk=dp[mb]-1;
        //  cout<<maxk<<endl;
         string kstring=bitset<32>(maxk).to_string();
         reverse(kstring.begin(),kstring.end());

        //  cout<<kstring<<endl;
         int n=v.size();
         long long curr_xor=0;
         for(auto i:v){
            curr_xor^=i;
         }

         vector<int>ans;
         for(int i=n-1; i>=0; i--){
             
             string tempk=kstring;
             string curr=bitset<32>(curr_xor).to_string();
            reverse(curr.begin(),curr.end());

        //    cout<<curr<<endl;
            for(int j=0;j<32;j++){

                if(curr[j]=='1'){
                    tempk[j]='0';
                }

            }
             
            //  cout<<tempk<<endl;

             int temp_ans=0;
             for(int i=0;i<32;i++){
                if(tempk[i]=='1'){
                    temp_ans+=dp[i];
                }
             } 
              curr_xor^=v[i];
              ans.push_back(temp_ans);

         }
             return ans;

    }
};