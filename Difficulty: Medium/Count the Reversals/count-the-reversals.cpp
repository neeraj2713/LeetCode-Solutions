//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    
cout << "~" << "\n";
}
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    // your code here
    if(s.length()%2 != 0) return -1;
    
    stack<char> st;
    
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        
        if(ch == '{'){
            st.push(ch);
        } else {
            if(!st.empty() && st.top() == '{') {
                st.pop();
            } else {
                st.push(ch);
            }
        }
    }
    
    int a = 0, b = 0;
    
    while(!st.empty()) {
        if(st.top() == '{') {
            b++;
        } else {
            a++;
        }
        st.pop();
    }
    
    int ans = (a+1)/2 + (b+1)/2;
    return ans;
    
}