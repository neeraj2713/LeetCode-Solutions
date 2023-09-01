class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t temp = n;
        int count = 0;

        while(temp){
            if(temp&1){
                count++;
            }
            temp = temp>>1;
        }

        return count;
    }
};