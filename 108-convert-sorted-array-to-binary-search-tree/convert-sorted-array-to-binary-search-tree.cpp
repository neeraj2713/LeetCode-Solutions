/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        return bst(nums, 0, nums.size()-1);
    }

    TreeNode* bst(vector<int>& nums, int left, int right){
        if(left > right) return NULL;
        int midPoint = left + (right-left)/2;
        TreeNode* node = new TreeNode(nums[midPoint]);
        node->left = bst(nums, left, midPoint-1);
        node->right = bst(nums,midPoint+1, right);

        return node;
    }
};