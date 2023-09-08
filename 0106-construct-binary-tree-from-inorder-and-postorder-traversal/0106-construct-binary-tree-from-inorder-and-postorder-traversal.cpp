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
    int Findposition(vector<int> inorder ,int inorderStart , int inorderEnd , int element ,int  n){
        for(int i = inorderStart ; i<=inorderEnd ;i++){
            if(inorder[i]==element){
                return i ; 
            }
        }
        return -1 ;
    }


    TreeNode* solve(vector<int> inorder, vector<int> postorder, int &index, int inorderStart, int inorderEnd, int n) {
        if(index<0 || inorderStart>inorderEnd){
            return NULL ;
        }
        
        int element = postorder[index--] ; // At every interation index is increasing
        TreeNode* root  = new TreeNode(element); 
        int position  = Findposition(inorder , inorderStart , inorderEnd ,element, n);
        
        root->right = solve(inorder , postorder , index , position+1 , inorderEnd ,n);
        root->left = solve(inorder , postorder , index  , inorderStart , position-1 ,n);
        
        return root ;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int preorderindex  = n-1 ;  
        TreeNode* ans = solve(inorder , postorder , preorderindex , 0  , n-1 , n );
        return ans ;
    }
};