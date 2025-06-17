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
    // unordered_map<TreeNode*,int> mp;
    int findHeight(TreeNode* root) {
        if(root == nullptr) return 0;
        
        // Check if height is already computed
        // if(mp.find(root) != mp.end()) return mp[root];
        
        // Use DFS to calculate height correctly
        int lh = findHeight(root->left);
        int rh = findHeight(root->right);
        if(lh ==-1 || rh == -1) return -1;
        if(abs(lh-rh)>1) return -1;
        
        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        // if(root == nullptr) return true;

        // int lh = findHeight(root->left);
        // int rh = findHeight(root->right);
        // if(root->left) cout << root->left->val << " ";
        // if(root->right) cout << root->right->val << " ";
        // cout << lh << " " << rh << endl;
        // if(abs(lh-rh)>1) return false;

        // int l = isBalanced(root->left);
        // int r = isBalanced(root->right);

        // return (l && r);
        if(findHeight(root)==-1) return false;
        return true;
    }
};