//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        stack<char>st;
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            if(ch=='(' || ch=='+' || ch=='-' || ch =='*' || ch=='/'){
                st.push(ch);
            }
            else{
                if(!st.empty() && ch==')'){
                    if(st.top() == '('){
                        return 1;
                    }
                    else{
                        while(st.top() != '('){
                            st.pop();
                        }
                        st.pop();
                    }
                }
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends