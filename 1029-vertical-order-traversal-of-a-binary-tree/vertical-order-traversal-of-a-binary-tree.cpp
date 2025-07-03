class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes; 
        queue<pair<TreeNode*, pair<int, int>>> q;
        vector<vector<int>> ans;

        if (!root) return ans;

        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto [node, pos] = q.front(); q.pop();
            int hd = pos.first;
            int lvl = pos.second;
            nodes[hd][lvl].insert(node->val);

            if (node->left) q.push({node->left, {hd - 1, lvl + 1}});
            if (node->right) q.push({node->right, {hd + 1, lvl + 1}});
        }

        for (auto& [hd, levels] : nodes) {
            vector<int> col;
            for (auto& [lvl, values] : levels) {
                col.insert(col.end(), values.begin(), values.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};
