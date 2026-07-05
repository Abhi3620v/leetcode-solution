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
    string helper(TreeNode* root, vector<TreeNode*>& ans, map<string, int>& mp ){
        if(root == NULL){
            return "#";
        }

        string left = helper(root->left, ans, mp);
        string right = helper(root->right, ans, mp);

        string curr =to_string(root->val)+","+left+","+right;

        mp[curr]++;

        if(mp[curr] == 2){
            ans.push_back(root);
        }

        return curr;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        map<string, int> mp;

        helper(root, ans, mp);

        return ans;

    }
};