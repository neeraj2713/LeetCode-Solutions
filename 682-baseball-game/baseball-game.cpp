class Solution {
public:
    int calPoints(vector<string>& operations) {
        int ans = 0;
        stack<int> st;
        for(int i=0;i<operations.size();i++){
            if(operations[i] == "+"){
                int score1 = st.top();
                st.pop();
                int score2 = st.top();
                st.push(score1);
                st.push(score1+score2);
            } else if(operations[i] == "D"){
                int score = st.top();
                st.push(score*2);
            } else if(operations[i] == "C"){
                st.pop();
            } else {
                st.push(stoi(operations[i]));
            }
        }

        while(!st.empty()){
            int num = st.top();
            st.pop();
            ans += num;
        }

        return ans;
    }
};