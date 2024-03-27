/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void serializeHelper(TreeNode* root, string& s){
        if(root == nullptr) return;

        s += to_string(root->val) + ",";
        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    TreeNode* deserializeHelper(string& data, int min, int max) {
        if(data.size() == 0) return nullptr;
        int pos = 0;
        int value = convertStringtoInt(data, pos);
        if(value < min || value > max) return nullptr;

        TreeNode* tnode = new TreeNode(value);
        data = data.substr(pos+1);
        tnode->left = deserializeHelper(data, min, tnode->val);
        tnode->right = deserializeHelper(data, tnode->val, max);
        return tnode;
    }

    int convertStringtoInt(string& data, int& pos){
        pos=data.find(',');
        int value = stoi(data.substr(0, pos));
        return value;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "";
        string s = "";
        serializeHelper(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return nullptr;
        return deserializeHelper(data, INT_MIN, INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;