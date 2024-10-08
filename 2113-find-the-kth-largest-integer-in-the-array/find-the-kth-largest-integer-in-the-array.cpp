class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        auto compare = [](const string& a, const string& b) {
            if(a.size() != b.size()){
                return a.size() > b.size();
            }

            return a > b;
        };

        priority_queue<string, vector<string>, decltype(compare)> pq;

        for (const string& num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
        
    }
};