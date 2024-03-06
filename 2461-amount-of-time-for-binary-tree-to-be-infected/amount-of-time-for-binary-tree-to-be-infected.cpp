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
private:
    int BurnTree(TreeNode* root, map<TreeNode*, TreeNode*> parent_track){
        int minutes = 0;
        unordered_map<TreeNode*, int> vis;
        vis[root] = 1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int flag = 0;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    flag = 1;
                    q.push(node->left);
                    vis[node->left] = 1;
                }

                if(node->right && !vis[node->right]){
                    flag = 1;
                    q.push(node->right);
                    vis[node->right] = 1;
                }

                if(parent_track[node] && !vis[parent_track[node]]){
                    flag = 1;
                    q.push(parent_track[node]);
                    vis[parent_track[node]] = 1;
                }
            }
            if(flag == 1) minutes++; 
        }

        return minutes;
    }

    TreeNode* ParentTrackFinder(TreeNode* root, int start, map<TreeNode*, TreeNode*>& parent_track){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->val == start) res = node;
            if(node->left){
                q.push(node->left);
                parent_track[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                parent_track[node->right] = node;
            }
        }

        return res;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> parent_track;
        TreeNode* target = ParentTrackFinder(root, start, parent_track);
        int maxi = BurnTree(target, parent_track);
        return maxi;
    }
};